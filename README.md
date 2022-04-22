# HW10-TSP-project-p2

This project is a collaboration between Tiago Beck and Mollie Boor. We used Eitan's implementation of the Cities class and his tsp.cc file, with the addition of a randomized search function. To test our randomized search, we used our solution from the first part of the project.

The project can be constructed using the included makefile. The makefile also includes a command for copying to patty.

### Deme
- **constructor:** creates a vector of pop_size many randomly-permuted Chromosome objects. Sets mutrate_ and generator_. Takes the sum of the fitness scores of all chromosomes, used for roulette scoring.
- **destructor:** deletes each chromosome in the deme population.
- **roulette_score, sum_fitness:** calculates the roulette probability linked to in the assignment description.
- **compute_next_generation:** selects pop_.size()/2 pairs of parent chromosomes, possibly mutates them, then combines them and puts their offspring into a new population vector.
- **get_best:** scans through the population vector to find the chromosome with highest fitness. 
- **select_parent:** uses the roulette probability system. Essentially, assigns a random number from 0 to 1 to the ball, which is where along the number line the ball will stop. Each chromosome has a slot along the line, the width of which is determined by its roulette score. Each time the ball passes through a slot, the width of the slot is subtracted from the random number and the ball passes into the next slot. When the ball's number is zero, it's in the slot that contains its original number and the corresponding chromosome is returned.

### Chromosome
- **constructor:** initalizes a pointer to a Cities object and randomly orders it.
- **destructor:** asserts that the chromosome is a valid chromosome, then left as default.
- **mutate:** selects two random indecies and swaps the values at them.
- **recombine:** selects a beginning and end index and creates two crossover children using that range.
- **create_crossover_child:** implemented by Eitan.
- **get_fitness:** returns the inverse of the distance of the route. Will always be between 0 and 100 with higher being a shorter route.
- **is_valid:** sorts the vector and then uses std::adjacent_find to check for duplicate entries. Also checks if largest element is greater than the number of cities minus 1. If neither of those are true, there are also no skipped cities and the chromosome is valid.
- **is_in_range:** calls std::find on a subrange of a vector to check for the given value.
