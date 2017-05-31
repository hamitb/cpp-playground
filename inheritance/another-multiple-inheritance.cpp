class Animal {
  private:
    float weight;
    float speed;
  public:
    
}

class Mammal: public Animal {
  private:
    float gestation-time;
  public:
}

class Flyer: public Animal {
  private:
    float wing-span;
  public:
}

class Bird: public Animal {
  private:
    float egg-size;
  public:
}

class Cat: public Mammal {
  public:
    void say_meow();
}

class Bat: public Mammal, public Flyer {
  private:
    float sonar_range;
  public:
}