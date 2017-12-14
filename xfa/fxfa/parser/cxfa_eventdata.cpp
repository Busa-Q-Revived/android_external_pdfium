// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_eventdata.h"

#include "xfa/fxfa/parser/cxfa_node.h"
#include "xfa/fxfa/parser/cxfa_script.h"
#include "xfa/fxfa/parser/cxfa_submit.h"

CXFA_EventData::CXFA_EventData(CXFA_Node* pNode) : CXFA_DataData(pNode) {}

XFA_AttributeEnum CXFA_EventData::GetActivity() {
  return m_pNode->JSObject()->GetEnum(XFA_Attribute::Activity);
}

XFA_Element CXFA_EventData::GetEventType() const {
  CXFA_Node* pChild = m_pNode->GetNodeItem(XFA_NODEITEM_FirstChild);
  while (pChild) {
    XFA_Element eType = pChild->GetElementType();
    if (eType != XFA_Element::Extras)
      return eType;

    pChild = pChild->GetNodeItem(XFA_NODEITEM_NextSibling);
  }
  return XFA_Element::Unknown;
}

WideString CXFA_EventData::GetRef() const {
  return m_pNode->JSObject()->GetCData(XFA_Attribute::Ref);
}

CXFA_Script* CXFA_EventData::GetScript() const {
  return m_pNode->GetChild<CXFA_Script>(0, XFA_Element::Script, false);
}

CXFA_Submit* CXFA_EventData::GetSubmit() const {
  return m_pNode->GetChild<CXFA_Submit>(0, XFA_Element::Submit, false);
}
