#!/usr/custom
# [args...]
# 	args	...	(program arguments)
job

#!/job/custom
info "$@"
IFS='' read -r 'line'
info "$line"
