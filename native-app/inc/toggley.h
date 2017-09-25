enum class ToggleyState {
  STATE_OFF,
  STATE_SWITCHING,
  STATE_ON
};

class Toggley {
public:
  Toggley();
  Toggley(ToggleyState toggleyState);
  void toggle();
  ToggleyState state();
  void setState(ToggleyState toggleyState);

private:
  ToggleyState _toggley_state;
};
