#!/bin/bash
`sed '/srand/i unsigned int seed = (unsigned)time(NULL);' ./stu.c > ./stu1.c`
sed -i '/srand/a printf("%d\\n", seed);' ./stu1.c
`sed -i '/srand/c srand(seed);' ./stu1.c`
check_filename="checker"
stu_filename="stu1"
echo "compiling ${check_filename}.c"
gcc -o ./${check_filename}.o ./${check_filename}.c
status=$?
if test $status -ne 0
then
    echo "ERROR: cannot compile ${check_filename}.c(return status ${status})"
    exit 1
fi
echo "compiling stu.c"
gcc -o ./${stu_filename}.o ./${stu_filename}.c
status=$?
if test $status -ne 0
then
    echo "ERROR: cannot compile ${stu_filename}.c(return status ${status})"
    exit 1
fi
score=0
for i in {1..20}
do
    timeout 1 ./${stu_filename}.o | ./${check_filename}.o
    result=$?
    if test ${result} -ge 0
    then
	echo "score: ${result}pts"
	score=`expr $result + $score`
    else
	echo "incorrect"
    fi
    sleep 1
done

rm -rf ./${stu_filename}.c
rm -rf ./${stu_filename}.o
rm -rf ./${check_filename}.o

echo "{\"scores\": {\"Correctness\": ${score}}}"
