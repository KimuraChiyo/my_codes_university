#!/bin/bash


RESTORE='\033[0m'
LRED='\033[01;31m'
LGREEN='\033[01;32m'

correct=0
cat_uncorrect=0
file="bytes.txt"
diff_res=""
VALGRIND_COMMAND="valgrind --quiet --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all ./s21_cat"

for opt in -b -e -n -s -t -v -E -T #--number-nonblank --number --squeeze-blank
do
          params="$opt $file"
		  ./s21_cat $params > s21_cat.log
		#   $VALGRIND_COMMAND $params > s21_cat.log
          cat $params > cat.log
		  diff_res=$(diff -s s21_cat.log cat.log)
		  if [ "$diff_res" == "Files s21_cat.log and cat.log are identical" ]
            then
			echo -en "${LGREEN}$params${RESTORE}\n"
              (( correct++ ))
            else
			echo -en "${LRED}$params${RESTORE}\n"
              (( cat_uncorrect++ ))
          fi
          rm s21_cat.log cat.log
done
for opt in -b -e -n -s -t -v -E -T # --number-nonblank --number --squeeze-blank
do
  for opt2 in -b -e -n -s -t -v -E -T # --number-nonblank --number --squeeze-blank
  do
        if [ $opt != $opt2 ]
        then
          params="$opt $opt2 $file"
		  ./s21_cat $params > s21_cat.log
		#   $VALGRIND_COMMAND $params > s21_cat.log
          cat $params > cat.log
		  diff_res=$(diff -s s21_cat.log cat.log)
      if [ "$diff_res" == "Files s21_cat.log and cat.log are identical" ]
            then
			echo -en "${LGREEN}$params${RESTORE}\n"
              (( correct++ ))
            else
			echo -en "${LRED}$params${RESTORE}\n"
              (( cat_uncorrect++ ))
          fi
          rm s21_cat.log cat.log
        fi
  done
done
for opt in -b -e -n -s -t -v -E -T # --number-nonblank --number --squeeze-blank
do
  for opt2 in -b -e -n -s -t -v -E -T # --number-nonblank --number --squeeze-blank
  do
      for opt3 in -b -e -n -s -t -v -E -T # --number-nonblank --number --squeeze-blank
      do
        if [ $opt != $opt2 ] && [ $opt2 != $opt3 ] && [ $opt != $opt3 ]
        then
          params="$opt $opt2 $opt3 $file"
		  ./s21_cat $params > s21_cat.log
        #   $VALGRIND_COMMAND $params > s21_cat.log
          cat $params > cat.log
		  diff_res=$(diff -s s21_cat.log cat.log)
		  if [ "$diff_res" == "Files s21_cat.log and cat.log are identical" ]
            then
			echo -en "${LGREEN} $params${RESTORE}\n"
              (( correct++ ))
            else
			echo -en "${LRED} $params${RESTORE}\n"
              (( cat_uncorrect++ ))
          fi
          rm s21_cat.log cat.log
        fi
      done
  done
done
echo -en "${LGREEN}SUCCESS: $correct${RESTORE}\n"
echo -en "${LRED}FAIL: $cat_uncorrect${RESTORE}\n"