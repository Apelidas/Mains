#!/bin/bash

fail() {
  message="$1"

  echo "test was failing: $message"
  exit 1
}

test_export(){

  rm -f minishell.out
  ./minishell << EndOfCommand || fail 'test_export'
export A='Variable'
echo $A > minishell.out
EndOfCommand
}

test_export