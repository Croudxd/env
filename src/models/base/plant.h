#pragma once
#include "graphics/renderobject.h"
#include "models/base/entity.h"
#include <vector>
class Plants : public Entity {
public:
  Plants(int energy, int rate_of_growth, int age_limit, int health,
         int photosynthsis_rate, std::vector<float> vertices)
      : energy(energy), rate_of_growth(rate_of_growth), age_limit(age_limit),
        health(health), photosynthsis_rate(photosynthsis_rate),
        render_obj(vertices) {}

  int get_energy() { return energy; }
  int get_rate_of_growth() { return rate_of_growth; }
  int get_age_limit() { return age_limit; }
  int get_health() { return health; }
  int get_photosynthsis_rate() { return photosynthsis_rate; }
  RenderObject get_render_obj() { return render_obj; }

  void set_energy(int energy) { this->energy = energy; };
  void set_rate_of_growth(int rate_of_growth) {
    this->rate_of_growth = rate_of_growth;
  };
  void set_age_limit(int age_limit) { this->age_limit = age_limit; };
  void set_health(int health) { this->health = health; };
  void set_photosynthsis_rate(int photosynthsis_rate) {
    this->photosynthsis_rate = photosynthsis_rate;
  };
  void set_render_obj(RenderObject render_obj) {
    this->render_obj = render_obj;
  };

protected:
  int energy;
  int rate_of_growth;
  int age_limit;
  int health;
  int photosynthsis_rate;
  RenderObject render_obj;
  // Pollination this can come later when we do breeding.
};
