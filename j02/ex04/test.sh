#!/bin/zsh

echo "False:"

arg="0t"
echo -n $arg; ./eval_expr $arg
arg="+"
echo -n $arg; ./eval_expr $arg
arg="-"
echo -n $arg; ./eval_expr $arg
arg="*"
echo -n $arg; ./eval_expr $arg
arg="/"
echo -n $arg; ./eval_expr $arg
arg=")"
echo -n $arg; ./eval_expr $arg
arg="("
echo -n $arg; ./eval_expr $arg
arg="--"
echo -n $arg; ./eval_expr $arg
arg="+-"
echo -n $arg; ./eval_expr $arg
arg="-()"
echo -n $arg; ./eval_expr $arg
arg="+()"
echo -n $arg; ./eval_expr $arg
arg="*()"
echo -n $arg; ./eval_expr $arg
arg="/()"
echo -n $arg; ./eval_expr $arg
arg="--()"
echo -n $arg; ./eval_expr $arg
arg="0++0"
echo -n $arg; ./eval_expr $arg
arg="0+-+0"
echo -n $arg; ./eval_expr $arg
arg="0+*0"
echo -n $arg; ./eval_expr $arg
arg="0+/0"
echo -n $arg; ./eval_expr $arg
arg="+)"
echo -n $arg; ./eval_expr $arg
arg="0---0"
echo -n $arg; ./eval_expr $arg
arg="0-+0"
echo -n $arg; ./eval_expr $arg
arg="0-*0"
echo -n $arg; ./eval_expr $arg
arg="0-/0"
echo -n $arg; ./eval_expr $arg
arg="-)"
echo -n $arg; ./eval_expr $arg
arg="0**0"
echo -n $arg; ./eval_expr $arg
arg="0*+0"
echo -n $arg; ./eval_expr $arg
arg="0*/0"
echo -n $arg; ./eval_expr $arg
arg="0*--0"
echo -n $arg; ./eval_expr $arg
arg="*)"
echo -n $arg; ./eval_expr $arg
arg="0//0"
echo -n $arg; ./eval_expr $arg
arg="0/+0"
echo -n $arg; ./eval_expr $arg
arg="0/*0"
echo -n $arg; ./eval_expr $arg
arg="0/--0"
echo -n $arg; ./eval_expr $arg
arg="/)"
echo -n $arg; ./eval_expr $arg
arg="(+"
echo -n $arg; ./eval_expr $arg
arg="(/"
echo -n $arg; ./eval_expr $arg
arg="(*"
echo -n $arg; ./eval_expr $arg
arg="(--"
echo -n $arg; ./eval_expr $arg
arg="0("
echo -n $arg; ./eval_expr $arg
arg=")--"
echo -n $arg; ./eval_expr $arg
arg=")("
echo -n $arg; ./eval_expr $arg
arg=")0"
echo -n $arg; ./eval_expr $arg
arg="0+()+0"
echo -n $arg; ./eval_expr $arg
arg="(0"
echo -n $arg; ./eval_expr $arg
arg="0)"
echo -n $arg; ./eval_expr $arg
arg="(0 + (0)"
echo -n $arg; ./eval_expr $arg
arg="(0 + 0 ) )"
echo -n $arg; ./eval_expr $arg
arg="0 + 0) + 0"
echo -n $arg; ./eval_expr $arg
arg="(0))) + (((0)) + 0"
echo -n $arg; ./eval_expr $arg
arg="."
echo -n $arg; ./eval_expr $arg
arg="4..6"
echo -n $arg; ./eval_expr $arg
arg="4.66. + 2"
echo -n $arg; ./eval_expr $arg
arg="1 + ."
echo -n $arg; ./eval_expr $arg
arg="1 + 2.(0)"
echo -n $arg; ./eval_expr $arg
arg="1 + (0).2"
echo -n $arg; ./eval_expr $arg
arg="(.)"
echo -n $arg; ./eval_expr $arg
arg="3.45.3"
echo -n $arg; ./eval_expr $arg


echo "True:"

arg="(0+(0)+-(-0)*-0--0/-1-(0)*(0)/(1)+0-0*0/1--(0))"
echo -n $arg; ./eval_expr $arg
arg="(0 + ((0) + 0))"
echo -n $arg; ./eval_expr $arg
arg=".4+4.12*0/1.-(.5 + 4.)"
echo -n $arg; ./eval_expr $arg

arg=".4"
echo -n $arg; ./eval_expr $arg

