#!/bin/bash


RESTORE='\033[0m'
LRED='\033[01;31m'
LGREEN='\033[01;32m'

correct=0
grep_uncorrect=0
diff_res=""
VALGRIND_COMMAND="valgrind --quiet --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all ./s21_grep"

one_file="grep1.txt"
two_files="grep1.txt grep2.txt"
patt_files="-f patterns.txt -f patterns1.txt"
e_patts="-e is -e abc -e aba"

for opt in -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
do
          params="$opt $one_file $e_patts"
		  ./s21_grep $params > s21_grep.log
		#   $VALGRIND_COMMAND $params > s21_grep.log
          grep $params > grep.log
		  diff_res=$(diff -s s21_grep.log grep.log)
		  if [ "$diff_res" == "Files s21_grep.log and grep.log are identical" ]
            then
			echo -en "${LGREEN}$params${RESTORE}\n"
              (( correct++ ))
            else
			  echo -en "${LRED}$params${RESTORE}\n"
              (( grep_uncorrect++ ))
          fi
          rm s21_grep.log grep.log 
done
for opt in -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
do
          params="$opt $one_file $patt_files"
		  ./s21_grep $params > s21_grep.log
        #   $VALGRIND_COMMAND $params > s21_grep.log
          grep $params > grep.log
		  diff_res=$(diff -s s21_grep.log grep.log)
		  if [ "$diff_res" == "Files s21_grep.log and grep.log are identical" ]
            then
			echo -en "${LGREEN}$params${RESTORE}\n"
              (( correct++ ))
            else
			  echo -en "${LRED}$params${RESTORE}\n"
              (( grep_uncorrect++ ))
          fi
          rm s21_grep.log grep.log 
done
for opt in -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
do
          params="$opt $one_file $patt_files $e_patts"
		  ./s21_grep $params > s21_grep.log
        #   $VALGRIND_COMMAND $params > s21_grep.log
          grep $params > grep.log
		  diff_res=$(diff -s s21_grep.log grep.log)
		  if [ "$diff_res" == "Files s21_grep.log and grep.log are identical" ]
            then
			echo -en "${LGREEN}$params${RESTORE}\n"
              (( correct++ ))
            else
			  echo -en "${LRED}$params${RESTORE}\n"
              (( grep_uncorrect++ ))
          fi
          rm s21_grep.log grep.log 
done
for opt in -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
do
          params="$opt $two_files $e_patts"
		  ./s21_grep $params > s21_grep.log
        #   $VALGRIND_COMMAND $params > s21_grep.log
          grep $params > grep.log
		  diff_res=$(diff -s s21_grep.log grep.log)
		  if [ "$diff_res" == "Files s21_grep.log and grep.log are identical" ]
            then
			echo -en "${LGREEN}$params${RESTORE}\n"
              (( correct++ ))
            else
			  echo -en "${LRED}$params${RESTORE}\n"
              (( grep_uncorrect++ ))
          fi
          rm s21_grep.log grep.log 
done
for opt in -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
do
          params="$opt $two_files $patt_files"
		  ./s21_grep $params > s21_grep.log
        #   $VALGRIND_COMMAND $params > s21_grep.log
          grep $params > grep.log
		  diff_res=$(diff -s s21_grep.log grep.log)
		  if [ "$diff_res" == "Files s21_grep.log and grep.log are identical" ]
            then
			echo -en "${LGREEN}$params${RESTORE}\n"
              (( correct++ ))
            else
			  echo -en "${LRED}$params${RESTORE}\n"
              (( grep_uncorrect++ ))
          fi
          rm s21_grep.log grep.log 
done
for opt in -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
do
          params="$opt $two_files $patt_files $e_patts"
		  ./s21_grep $params > s21_grep.log
        #   $VALGRIND_COMMAND $params > s21_grep.log
          grep $params > grep.log
		  diff_res=$(diff -s s21_grep.log grep.log)
		  if [ "$diff_res" == "Files s21_grep.log and grep.log are identical" ]
            then
			echo -en "${LGREEN}$params${RESTORE}\n"
              (( correct++ ))
            else
			  echo -en "${LRED}$params${RESTORE}\n"
              (( grep_uncorrect++ ))
          fi
          rm s21_grep.log grep.log 
done
for opt in  -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
do
  for opt2 in  -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
  do
        if [ $opt != $opt2 ]
        then
          params="$opt $opt2 $e_patts $one_file"
		  ./s21_grep $params > s21_grep.log
        #   $VALGRIND_COMMAND $params > s21_grep.log
          grep $params > grep.log
		  diff_res=$(diff -s s21_grep.log grep.log)
		  if [ "$diff_res" == "Files s21_grep.log and grep.log are identical" ]
            then
			echo -en "${LGREEN}$params${RESTORE}\n"
              (( correct++ ))
            else
			  echo -en "${LRED}$params${RESTORE}\n"
              (( grep_uncorrect++ ))
          fi
          rm s21_grep.log grep.log
        fi
  done
done
for opt in  -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
do
  for opt2 in  -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
  do
        if [ $opt != $opt2 ]
        then
          params="$opt $opt2 $patt_files $one_file"
		  ./s21_grep $params > s21_grep.log
        #   $VALGRIND_COMMAND $params > s21_grep.log
          grep $params > grep.log
		  diff_res=$(diff -s s21_grep.log grep.log)
		  if [ "$diff_res" == "Files s21_grep.log and grep.log are identical" ]
            then
			echo -en "${LGREEN}$params${RESTORE}\n"
              (( correct++ ))
            else
			  echo -en "${LRED}$params${RESTORE}\n"
              (( grep_uncorrect++ ))
          fi
          rm s21_grep.log grep.log
        fi
  done
done

for opt in  -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
do
  for opt2 in  -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
  do
        if [ $opt != $opt2 ]
        then
          params="$opt $opt2 $e_patts $patt_files $one_file"
		  ./s21_grep $params > s21_grep.log
        #   $VALGRIND_COMMAND $params > s21_grep.log
          grep $params > grep.log
		  diff_res=$(diff -s s21_grep.log grep.log)
		  if [ "$diff_res" == "Files s21_grep.log and grep.log are identical" ]
            then
			echo -en "${LGREEN}$params${RESTORE}\n"
              (( correct++ ))
            else
			  echo -en "${LRED}$params${RESTORE}\n"
              (( grep_uncorrect++ ))
          fi
          rm s21_grep.log grep.log
        fi
  done
done

for opt in  -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
do
  for opt2 in  -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
  do
        if [ $opt != $opt2 ]
        then
          params="$opt $opt2 $e_patts $two_files"
		  ./s21_grep $params > s21_grep.log
        #   $VALGRIND_COMMAND $params > s21_grep.log
          grep $params > grep.log
		  diff_res=$(diff -s s21_grep.log grep.log)
		  if [ "$diff_res" == "Files s21_grep.log and grep.log are identical" ]
            then
			echo -en "${LGREEN}$params${RESTORE}\n"
              (( correct++ ))
            else
			  echo -en "${LRED}$params${RESTORE}\n"
              (( grep_uncorrect++ ))
          fi
          rm s21_grep.log grep.log
        fi
  done
done
for opt in  -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
do
  for opt2 in  -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
  do
        if [ $opt != $opt2 ]
        then
          params="$opt $opt2 $patt_files $two_files"
		  ./s21_grep $params > s21_grep.log
        #   $VALGRIND_COMMAND $params > s21_grep.log
          grep $params > grep.log
		  diff_res=$(diff -s s21_grep.log grep.log)
		  if [ "$diff_res" == "Files s21_grep.log and grep.log are identical" ]
            then
			echo -en "${LGREEN}$params${RESTORE}\n"
              (( correct++ ))
            else
			  echo -en "${LRED}$params${RESTORE}\n"
              (( grep_uncorrect++ ))
          fi
          rm s21_grep.log grep.log
        fi
  done
done
for opt in  -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
do
  for opt2 in  -i -v -c -l -n -h -s -o # --ignore-case --invert-match --count --files-with-matches --line-number --no-filename --no-messages --only-matching
  do
        if [ $opt != $opt2 ]
        then
          params="$opt $opt2 $e_patts $patt_files $two_files"
		  ./s21_grep $params > s21_grep.log
        #   $VALGRIND_COMMAND $params > s21_grep.log
          grep $params > grep.log
		  diff_res=$(diff -s s21_grep.log grep.log)
		  if [ "$diff_res" == "Files s21_grep.log and grep.log are identical" ]
            then
			echo -en "${LGREEN}$params${RESTORE}\n"
              (( correct++ ))
            else
			  echo -en "${LRED}$params${RESTORE}\n"
              (( grep_uncorrect++ ))
          fi
          rm s21_grep.log grep.log
        fi
  done
done
echo -en "${LGREEN}SUCCESS: $correct${RESTORE}\n"
echo -en "${LRED}FAIL: $grep_uncorrect${RESTORE}\n"