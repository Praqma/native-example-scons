#include "toggley.h"

Toggley::Toggley()
  : _toggley_state(ToggleyState::STATE_OFF) {
}

Toggley::Toggley(ToggleyState toggleyState) {
    _toggley_state = toggleyState;
}

void Toggley::toggle() {
  switch(_toggley_state) {
    case ToggleyState::STATE_OFF :
      _toggley_state = ToggleyState::STATE_ON;
      break;
    case ToggleyState::STATE_ON :
      _toggley_state = ToggleyState::STATE_OFF;
      break;
    default:
      break;
  }
}

ToggleyState Toggley::state() {
  return _toggley_state;
}

void Toggley::setState(ToggleyState toggleyState) {
  _toggley_state = toggleyState;
}
