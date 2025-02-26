// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "flutter/testing/testing.h"  // IWYU pragma: keep
#include "gtest/gtest.h"
#include "impeller/renderer/backend/gles/proc_table_gles.h"
#include "impeller/renderer/backend/gles/test/mock_gles.h"

namespace impeller {
namespace testing {

TEST(CapabilitiesGLES, CanInitializeWithDefaults) {
  auto mock_gles = MockGLES::Init();

  auto capabilities = mock_gles->GetProcTable().GetCapabilities();

  EXPECT_FALSE(capabilities->SupportsOffscreenMSAA());
  EXPECT_FALSE(capabilities->SupportsSSBO());
  EXPECT_FALSE(capabilities->SupportsBufferToTextureBlits());
  EXPECT_FALSE(capabilities->SupportsTextureToTextureBlits());
  EXPECT_FALSE(capabilities->SupportsFramebufferFetch());
  EXPECT_FALSE(capabilities->SupportsCompute());
  EXPECT_FALSE(capabilities->SupportsComputeSubgroups());
  EXPECT_FALSE(capabilities->SupportsReadFromOnscreenTexture());
  EXPECT_FALSE(capabilities->SupportsReadFromResolve());
  EXPECT_FALSE(capabilities->SupportsDecalSamplerAddressMode());
  EXPECT_FALSE(capabilities->SupportsDeviceTransientTextures());

  EXPECT_EQ(capabilities->GetDefaultColorFormat(),
            PixelFormat::kR8G8B8A8UNormInt);
  EXPECT_EQ(capabilities->GetDefaultStencilFormat(), PixelFormat::kS8UInt);
  EXPECT_EQ(capabilities->GetDefaultDepthStencilFormat(),
            PixelFormat::kD24UnormS8Uint);
}

}  // namespace testing
}  // namespace impeller
