/*
 * Declarations for Deme class to evolve a genetic algorithm for the
 * travelling-salesperson problem.  A deme is a population of individuals.
 */

#include "chromosome.hh"
#include "deme.hh"

// Generate a Deme of the specified size with all-random chromosomes.
// Also receives a mutation rate in the range [0-1].
Deme::Deme(const Cities* cities_ptr, unsigned pop_size, double mut_rate)
{
  std::vector<Chromosome*> pop_;
  uint i = 0;
  while (i < pop_size){
    Chromosome c = Chromosome(cities_ptr); // randomly ordered by constructor
    pop_.push_back(&c);
    i++;
  }

  double mut_rate_ = mut_rate;
  std::default_random_engine generator_;
  double pop_fit_ = sum_fitness();
}

// Clean up as necessary
Deme::~Deme()
{
  // Add your implementation here
}

// Calculate the roulette selection score of a given chromosome in the population
double Deme::roulette_score(Chromosome* c){
  return (c->get_fitness()/pop_fit_);
}

// Take the total fitness of the population, for roulette
double Deme::sum_fitness(){
  double sum = 0;
  for (auto c : pop_){
    sum += c->get_fitness();
  }
  return sum;
}



// Evolve a single generation of new chromosomes, as follows:
// We select pop_size/2 pairs of chromosomes (using the select() method below).
// Each chromosome in the pair can be randomly selected for mutation, with
// probability mut_rate, in which case it calls the chromosome mutate() method.
// Then, the pair is recombined once (using the recombine() method) to generate
// a new pair of chromosomes, which are stored in the Deme.
// After we've generated pop_size new chromosomes, we delete all the old ones.
void Deme::compute_next_generation()
{
  // Add your implementation here
  std::vector<Chromosome*> new_pop;
  uint i = 0;

  while (i < pop_.size()/2){
    auto parent1 = select_parent();
    auto parent2 = select_parent();
    while (parent2 == parent1){
      parent2 = select_parent();
    }

    const double mut_chance1 = // make a random number [0,1]
    if (mut_chance1 >= mut_rate_){
      parent1->mutate();
    }
    const double mut_chance2 = // make a random number [0,1]
    if (mut_chance2 >= mut_rate_){
      parent2-> mutate()
    }
    auto offspring = parent1->recombine(parent2);
    new_pop.push_back(offspring.first);
    new_pop.push_back(offspring.second);

    i++
  }
  pop_ = new_pop; // ignore parent generation, use only child generation
  pop_fit_ = sum_fitness() // find new total fitness score
}

// Return a copy of the chromosome with the highest fitness.
const Chromosome* Deme::get_best() const
{
  Chromosome* best = pop_[0];
  for (auto c : pop_){
    if (c->get_fitness() > best->get_fitness()){
      best = c;
    }
  }
  return best;
}

// Randomly select a chromosome in the population based on fitness and
// return a pointer to that chromosome.
Chromosome* Deme::select_parent()
{
  const double prob = // make a random number [0,100], new prob for each pair
  int i = // random number 0 to pop_.size()-1
  while (roulette_score(pop_[i]) < prob){
    int i = // random number 0 to pop_.size()-1
  }
  return pop_[i];
}
