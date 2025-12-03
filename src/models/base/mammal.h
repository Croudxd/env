class mammals {
public:
  int get_max_speed() { return max_speed; }
  int get_energy() { return energy; }
  int get_rate_of_growth() { return rate_of_growth; }
  int get_age_limit() { return age_limit; }
  int get_perception_in_day() { return perception_in_day; }
  int get_perception_in_night() { return perception_in_night; }
  int get_hours_of_sleep() { return hours_of_sleep; }
  int get_hours_of_sleep_required() { return hours_of_sleep_required; }
  int get_sleep_type() { return sleep_type; }
  int get_endurance() { return endurance; }
  bool get_spritinng() { return spritinng; }
  bool get_walking() { return walking; }
  int get_type_of_eater() { return type_of_eater; }

protected:
  int max_speed;
  int energy;
  int rate_of_growth;
  int age_limit;
  int perception_in_day;
  int perception_in_night;
  int hours_of_sleep;
  int hours_of_sleep_required;
  int sleep_type;
  int endurance;
  bool spritinng;
  bool walking;
  int type_of_eater;
};
