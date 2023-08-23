
class Animal
{

};

// avoid double include part-class from Animal
class Bird : virtual public Animal
{

};

// avoid double include part-class from Animal
class Horse: virtual public Animal
{

};

class Pegasus: public Bird, public Horse
{

};
