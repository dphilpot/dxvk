#pragma once

#include "dxbc_common.h"
#include "dxbc_decoder.h"
#include "dxbc_enums.h"
#include "dxbc_reader.h"
#include "dxbc_type.h"

namespace dxvk {
  
  /**
   * \brief Signature entry
   * 
   * Stores the semantic name of an input or
   * output and the corresponding register.
   */
  struct DxbcSgnEntry {
    std::string       semanticName;
    uint32_t          semanticIndex;
    uint32_t          registerId;
    DxbcComponentMask componentMask;
    DxbcScalarType    componentType;
    DxbcSystemValue   systemValue;
  };
  
  /**
   * \brief Input/Output signature chunk
   * 
   * Stores information about the input and
   * output registers used by the shader stage.
   */
  class DxbcIsgn : public RcObject {
    
  public:
    
    DxbcIsgn(DxbcReader reader);
    ~DxbcIsgn();
    
    uint32_t entryCount() const;
    
    const DxbcSgnEntry& entry(uint32_t id) const;
    
  private:
    
    std::vector<DxbcSgnEntry> m_entries;
    
  };
  
}