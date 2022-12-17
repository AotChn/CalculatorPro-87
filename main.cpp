#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <map>

//TEST FILES ------------------------------------------------------>[]
#include "includes/rpn/rpn.h"
#include "includes/node/node.h"
#include "includes/token/token.h"
#include "includes/token/operator.h"
#include "includes/token/integer.h"
#include "includes/token/function.h"
#include "includes/token/leftparen.h"
#include "includes/token/rightparen.h"
#include "includes/token/function.h"
#include "includes/queue/MyQueue.h"
#include "includes/token/constants.h"
#include "includes/Graphics/window.h"
#include "includes/Graphics/animate.h"
#include "includes/Graphics/system.h"
#include "includes/Graphics/sidebar.h"
#include "includes/tokenizer/tokenizer.h"
#include "includes/shunting_yard/shunting_yard.h"
#include "includes/linked_list_functions/linked_list_functions.h"

//++++++++++ ------------------------------------------------------>[]
using namespace std;

int main(int argv, char** argc) {
    cout << "\n\n"<< endl;

   Animate calculator;
   calculator.run();

    cout << "\n\n\n=====================" << endl;
    return 0;
}

