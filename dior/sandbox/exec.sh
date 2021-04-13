#!/bin/bash

problem_name=APM
sandbox=$(dirname "$0")

"${sandbox}/${problem_name}.exe" "$@"
