
class plants {
public:
  plants(int energy, int rate_of_growth, int age_limit, int health,
         int photosynthsis_rate) {
    this->energy = energy;
    this->rate_of_growth = rate_of_growth;
    this->age_limit = age_limit;
    this->health = health;
    this->photosynthsis_rate = photosynthsis_rate;
  }
  int get_energy() { return energy; }
  int get_rate_of_growth() { return rate_of_growth; }
  int get_age_limit() { return age_limit; }
  int get_health() { return health; }
  int get_photosynthsis_rate() { return photosynthsis_rate; }

protected:
  int energy;
  int rate_of_growth;
  int age_limit;
  int health;
  int photosynthsis_rate;
  // Pollination this can come later when we do breeding.
};
