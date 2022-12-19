## PROGRESS
**things that need to get done**
# FILE DOCUMENTATION CHECK LIST 

**PHASE 0 - desc for File (stamp)**

**PHASE 1 - desc for all functions**

**PHASE 2 - desc for Algorithmn**

add_entry [2]
array_functions [2]

**DATA WRAPPERS**
function_data [2]
graph_info [2]
tk_data [2]

**GRAPHICS**
animate [2]
sidebar [2]
system [2]
window [2]

**CONTAINERS**
linked_list_functions [2]
node [2]
MyQueue [2]
MyStack [2]
vector [2]

**PLOTTING**
plot [2]
translator [2]
rpn [2]
shunting_yard [2]
all tokens [2]


# TODO LIST:

<\br>
fix memory leak in tokenizer, shuntingyard;
when we pop() the token* we are not actually deleting the items
- must find a way to delete those items 
<\br>
adjust screen size when the user resizes screen 
- must update everything everytime user does that
<\br>
fix negative operator
- right now unary negative is an operator that takes 2 arguments in rpn
- perhaps switch unary negative into a function 
<\br>
fix graph zoom as we go out past factor of 24 or zoom in past factor of 7
- must find ratio of pan displacement as zoom in/out
<\br>
implement mouse zoom in/out
- use mouse position to find displacement of graph and create a zoom off the new origin aka(mouse pos)
<\br>

### last update by Aot Chanthorn Dec 18, 2022 .