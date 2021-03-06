/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Mozilla Corporation code.
 *
 * The Initial Developer of the Original Code is Mozilla Foundation.
 * Portions created by the Initial Developer are Copyright (C) 2009
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Robert O'Callahan <robert@ocallahan.org>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef GFX_COLORLAYEROGL_H
#define GFX_COLORLAYEROGL_H

#ifdef MOZ_IPC
# include "mozilla/layers/PLayers.h"
# include "mozilla/layers/ShadowLayers.h"
#endif  // MOZ_IPC

#include "LayerManagerOGL.h"

namespace mozilla {
namespace layers {

class THEBES_API ColorLayerOGL : public ColorLayer,
                                 public LayerOGL
{
public:
  ColorLayerOGL(LayerManagerOGL *aManager)
    : ColorLayer(aManager, NULL)
    , LayerOGL(aManager)
  { 
    mImplData = static_cast<LayerOGL*>(this);
  }
  ~ColorLayerOGL() { Destroy(); }

  // LayerOGL Implementation
  virtual Layer* GetLayer() { return this; }

  virtual void Destroy() { mDestroyed = PR_TRUE; }

  virtual void RenderLayer(int aPreviousFrameBuffer,
                           const nsIntPoint& aOffset);
};

#ifdef MOZ_IPC
class ShadowColorLayerOGL : public ShadowColorLayer,
                            public LayerOGL
{
public:
  ShadowColorLayerOGL(LayerManagerOGL *aManager)
    : ShadowColorLayer(aManager, NULL)
    , LayerOGL(aManager)
  { 
    mImplData = static_cast<LayerOGL*>(this);
  }
  ~ShadowColorLayerOGL() { Destroy(); }

  // LayerOGL Implementation
  virtual Layer* GetLayer() { return this; }

  virtual void Destroy() { mDestroyed = PR_TRUE; }

  virtual void RenderLayer(int aPreviousFrameBuffer,
                           const nsIntPoint& aOffset);
};
#endif  // MOZ_IPC

} /* layers */
} /* mozilla */
#endif /* GFX_COLORLAYEROGL_H */
