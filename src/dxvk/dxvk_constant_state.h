#pragma once

#include "dxvk_buffer.h"
#include "dxvk_framebuffer.h"
#include "dxvk_limits.h"
#include "dxvk_resource.h"
#include "dxvk_shader.h"

namespace dxvk {
  
  /**
   * \brief Blend constants
   * 
   * Stores a blend factor
   * as an RGBA color value.
   */
  struct DxvkBlendConstants {
    float r, g, b, a;
  };
  
  
  /**
   * \brief Input assembly state
   * 
   * Stores the primitive topology and
   * whether or not primitive restart
   * is enabled.
   */
  struct DxvkInputAssemblyState {
    VkPrimitiveTopology primitiveTopology;
    VkBool32            primitiveRestart;
    uint32_t            patchVertexCount;
  };
  
  
  /**
   * \brief Rasterizer state
   * 
   * Stores the operating mode of the
   * rasterizer, including the depth bias.
   */
  struct DxvkRasterizerState {
    VkPolygonMode       polygonMode;
    VkCullModeFlags     cullMode;
    VkFrontFace         frontFace;
    VkBool32            depthClampEnable;
    VkBool32            depthBiasEnable;
    float               depthBiasConstant;
    float               depthBiasClamp;
    float               depthBiasSlope;
    VkSampleCountFlags  sampleCount;
  };
  
  
  /**
   * \brief Multisample state
   * 
   * Defines how to handle certain
   * aspects of multisampling.
   */
  struct DxvkMultisampleState {
    uint32_t            sampleMask;
    VkBool32            enableAlphaToCoverage;
    VkBool32            enableAlphaToOne;
  };
  
  
  /**
   * \brief Depth-stencil state
   * 
   * Defines the depth test and stencil
   * operations for the graphics pipeline.
   */
  struct DxvkDepthStencilState {
    VkBool32            enableDepthTest;
    VkBool32            enableDepthWrite;
    VkBool32            enableStencilTest;
    VkCompareOp         depthCompareOp;
    VkStencilOpState    stencilOpFront;
    VkStencilOpState    stencilOpBack;
  };
  
  
  /**
   * \brief Logic op state
   * Defines a logic op.
   */
  struct DxvkLogicOpState {
    VkBool32  enableLogicOp;
    VkLogicOp logicOp;
  };
  
  
  /**
   * \brief Blend mode for a single attachment
   * 
   * Stores the blend state for a single color attachment.
   * Blend modes can be set separately for each attachment.
   */
  struct DxvkBlendMode {
    VkBool32              enableBlending;
    VkBlendFactor         colorSrcFactor;
    VkBlendFactor         colorDstFactor;
    VkBlendOp             colorBlendOp;
    VkBlendFactor         alphaSrcFactor;
    VkBlendFactor         alphaDstFactor;
    VkBlendOp             alphaBlendOp;
    VkColorComponentFlags writeMask;
  };
  
  
  /**
   * \brief Vertex attribute description
   * 
   * Stores information about a
   * single vertex attribute.
   */
  struct DxvkVertexAttribute {
    uint32_t location;
    uint32_t binding;
    VkFormat format;
    uint32_t offset;
  };
  
  
  /**
   * \brief Vertex binding description
   * 
   * Stores information about a
   * single vertex binding slot.
   */
  struct DxvkVertexBinding {
    uint32_t          binding;
    uint32_t          fetchRate;
    VkVertexInputRate inputRate;
  };
  
  
  /**
   * \brief Input layout
   * 
   * Stores the description of all active
   * vertex attributes and vertex bindings.
   */
  struct DxvkInputLayout {
    uint32_t numAttributes;
    uint32_t numBindings;
    
    std::array<DxvkVertexAttribute, DxvkLimits::MaxNumVertexAttributes> attributes;
    std::array<DxvkVertexBinding,   DxvkLimits::MaxNumVertexBindings>   bindings;
  };
  
}