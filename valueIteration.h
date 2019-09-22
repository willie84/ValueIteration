//
//  valueIteration.hpp
//  valueIteration
//
//  Created by Willie Macharia on 2019/09/21.
//  Copyright © 2019 Willie Macharia. All rights reserved.
//

#ifndef valueIteration_hpp
#define valueIteration_hpp

#include <stdio.h>

#include "State.h"

#include <vector>
#include <string>

namespace MCHWIL006{
    std::vector<std::vector<MCHWIL006::state>> createAGrid();
    //double action_reward(MCHWIL006::Point f,MCHWIL006::Point b);
    void iterate();
    bool grids_converge(std::vector<std::vector<double>> gridc,std::vector<std::vector<double>> gridcom);
    //MCHWIL006::state optimal_state(std::vector<MCHWIL006::state> v);
    std::vector<MCHWIL006::state>  findOptimal(MCHWIL006::state startingpoint,std::vector<std::vector<MCHWIL006::state>> gridco);

}

#endif /* valueIteration_hpp */
