#Q1. File Extension Organizer
Create a directory named extension_practice_<your_id> with the following folders:
extension_practice_<your_id>/
├── source/
├── documents/
├── images/
├── scripts/
└── others/
Inside the source directory, create the following files:
a.txt
b.pdf
c.jpg
d.png
run.sh
test.c
note.doc
index.html

Write a shell script named organize_files.sh that:
1. Moves .txt, .pdf, and .doc files into documents
2. Moves .jpg and .png files into images
3. Moves .sh and .c files into scripts
4. Moves all remaining files into others
5. Displays the contents of each folder after moving

## code
```cpp
#!/bin/bash

# go to source folder
cd source

# move document files
mv *.txt ../documents/
mv *.pdf ../documents/
mv *.doc ../documents/

# move image files
mv *.jpg ../images/
mv *.png ../images/

# move script and c files
mv *.sh ../scripts/
mv *.c ../scripts/

# move remaining files to others
mv * ../others/ 2>/dev/null

# show results
echo "Documents folder:"
ls ../documents/

echo ""
echo "Images folder:"
ls ../images/

echo ""
echo "Scripts folder:"
ls ../scripts/

echo ""
echo "Others folder:"
ls ../others/
```
#Q2. Delete Files by Extension Length
Create a directory named clean_lab_<your_id> with a folder named temp.
Inside temp, create the following files:
one.c
two.sh
three.txt
four.java
five.log
six.py
seven.html
eight.csv

Write a shell script named clean_files.sh that:
1. Deletes files whose extension length is exactly 2 characters
2. Keeps all other files
3. Saves the names of deleted files into deleted.log
4. Displays the remaining files

##code
```
#!/bin/bash

# go to temp folder
cd temp

# log file (outside temp or inside, your choice)
log_file="../deleted.log"

# clear previous log
> "$log_file"

# loop through all files
for file in *
do
    # check if it is a file
    if [ -f "$file" ]
    then
        # extract extension
        ext="${file##*.}"

        # check extension length
        len=${#ext}

        if [ "$len" -eq 2 ]
        then
            # save deleted file name
            echo "$file" >> "$log_file"

            # delete file
            rm "$file"
        fi
    fi
done

# show remaining files
echo "Remaining files:"
ls
```
#Q3. Number Array Analysis
Create a shell script named number_analysis.sh.
The script should:
1. Take 6 numbers as input from the user
2. Store them in an array
3. Display all even numbers
4. Display all odd numbers
5. Display the largest and smallest number

##code
```
#!/bin/bash

array=()

# take 6 numbers input
for (( i=0; i<6; i++ ))
do
    read -p "Enter number: " num
    array[i]=$num
done

echo ""
echo "Even numbers:"

# display even numbers
for (( i=0; i<6; i++ ))
do
    if (( array[i] % 2 == 0 ))
    then
        echo "${array[i]}"
    fi
done

echo ""
echo "Odd numbers:"

# display odd numbers
for (( i=0; i<6; i++ ))
do
    if (( array[i] % 2 != 0 ))
    then
        echo "${array[i]}"
    fi
done

# initialize min and max
min=${array[0]}
max=${array[0]}

# find min and max
for (( i=1; i<6; i++ ))
do
    if (( array[i] < min ))
    then
        min=${array[i]}
    fi

    if (( array[i] > max ))
    then
        max=${array[i]}
    fi
done

echo ""
echo "Smallest number: $min"
echo "Largest number: $max"
```

#Q4. Search Number in Array
Create a shell script named search_array.sh.
The script should:
1. Store the following numbers in an array:
12 45 67 23 89 10 5 34
2. Ask the user to enter a number
3. Search whether the number exists in the array
4. If found, display Number found at position <position>
5. If not found, display Number not found
##code
#!/bin/bash

# given array
array=(12 45 67 23 89 10 5 34)

# input from user
read -p "Enter a number: " num

found=0

# search in array
for (( i=0; i<8; i++ ))
do
    if (( array[i] == num ))
    then
        echo "Number found at position $((i+1))"
        found=1
        break
    fi
done

# if not found
if (( found == 0 ))
then
    echo "Number not found"
fi
```

#Q5. String Character Counter
Create a shell script named string_counter.sh.

The script should:
1. Ask the user to enter a string
2. Count the total number of characters
3. Count the number of vowels
4. Count the number of consonants
5. Display all counts clearly

##code
```cpp
#!/bin/bash

# input string
read -p "Enter a string: " s

# total characters
total=${#s}

vowel_count=0
consonant_count=0

# loop through each character
for (( i=0; i<total; i++ ))
do
    ch=${s:$i:1}

    # check vowels
    if [[ "$ch" == "a" || "$ch" == "e" || "$ch" == "i" || "$ch" == "o" || "$ch" == "u" ||
          "$ch" == "A" || "$ch" == "E" || "$ch" == "I" || "$ch" == "O" || "$ch" == "U" ]]
    then
        ((vowel_count++))

    # check alphabet (consonant)
    elif [[ "$ch" =~ [a-zA-Z] ]]
    then
        ((consonant_count++))
    fi
done

# display results
echo "Total characters: $total"
echo "Vowels: $vowel_count"
echo "Consonants: $consonant_count"
```
#Q6. Palindrome Word Checker
Create a shell script named word_palindrome.sh.
The script should:
1. Ask the user to enter a word
2. Reverse the word
3. Check whether the word is a palindrome
4. Display Palindrome if it matches
5. Display Not Palindrome if it does not match

##code
```cpp
#!/bin/bash

# input word
read -p "Enter a word: " word

# reverse the word
rev=$(rev <<< "$word")

# check palindrome
if [ "$word" == "$rev" ]
then
    echo "Palindrome"
else
    echo "Not Palindrome"
fi
```
#Q7. Student Attendance File Practice
Create a directory named attendance_lab_<your_id> with folders:
data/
present/
absent/
scripts/
Inside data, create a file named attendance.txt with the following content:

ID Name Status
301 Rahim Present
302 Karim Absent
303 Ayesha Present
304 Nadia Absent
305 Hasan Present
306 Mitu Present
307 Tanvir Absent

Write a shell script named attendance_filter.sh that:
1. Uses grep to find Present students
2. Saves Present students into present/present_list.txt
3. Uses grep to find Absent students
4. Saves Absent students into absent/absent_list.txt
5. Displays the count of Present and Absent students

##code
```cpp
#!/bin/bash

# file path
data_file="../data/attendance.txt"

# find Present students
present_result=$(grep "Present" "$data_file")

# save Present students
echo "$present_result" > ../present/present_list.txt

# find Absent students
absent_result=$(grep "Absent" "$data_file")

# save Absent students
echo "$absent_result" > ../absent/absent_list.txt

# count Present
present_count=$(echo "$present_result" | wc -l)

# count Absent
absent_count=$(echo "$absent_result" | wc -l)

# display results
echo "Present students count: $present_count"
echo "Absent students count: $absent_count"
```
#Q8. Function-Based Calculator
Create a shell script named calculator.sh.
The script should:
1. Define four functions: add, subtract, multiply, divide
2. Ask the user to enter two numbers
3. Ask the user to choose an operation
4. Call the correct function based on the user’s choice
5. Display the result

```cpp
#!/bin/bash

# function for addition
add() {
    result=$((num1 + num2))
    echo "Result: $result"
}

# function for subtraction
subtract() {
    result=$((num1 - num2))
    echo "Result: $result"
}

# function for multiplication
multiply() {
    result=$((num1 * num2))
    echo "Result: $result"
}

# function for division
divide() {
    if [ "$num2" -eq 0 ]
    then
        echo "Error: Division by zero"
    else
        result=$((num1 / num2))
        echo "Result: $result"
    fi
}

# take input
read -p "Enter first number: " num1
read -p "Enter second number: " num2

# choose operation
echo "Choose operation:"
echo "1. Add"
echo "2. Subtract"
echo "3. Multiply"
echo "4. Divide"

read -p "Enter choice: " choice

# call function based on choice
if [ "$choice" -eq 1 ]
then
    add
elif [ "$choice" -eq 2 ]
then
    subtract
elif [ "$choice" -eq 3 ]
then
    multiply
elif [ "$choice" -eq 4 ]
then
    divide
else
    echo "Invalid choice"
fi
```

#Q9. Rename Files Using Loop
Create a directory named rename_lab_<your_id> with a folder named files.
Inside files, create the following files:

report1.txt
report2.txt
report3.txt
report4.txt

Write a shell script named rename_reports.sh that:
1. Uses a loop to rename each file
2. Adds the word old_ before each filename
Example:
report1.txt becomes old_report1.txt
3. Displays all renamed files

##code
```cpp
#!/bin/bash

# go to files folder
cd files

# loop through all report files
for file in report1.txt report2.txt report3.txt report4.txt
do
    new_name="old_$file"
    mv "$file" "$new_name"
done

echo "Renamed files:"
ls
```

#Q10. Prime Number Practice
Create a shell script named prime_range.sh.
The script should:
1. Ask the user to enter a starting number
2. Ask the user to enter an ending number
3. Use a loop to check each number in the range
4. Display only the prime numbers
5. Use a function named is_prime to check whether a number is prime

```cpp
#!/bin/bash

is_prime() {
    n=$1

    if [ "$n" -le 1 ]
    then
        return 1
    fi

    for (( i=2; i<n; i++ ))
    do
        if [ $((n % i)) -eq 0 ]
        then
            return 1
        fi
    done

    return 0
}

read -p "Enter starting number: " start
read -p "Enter ending number: " end

for (( num=start; num<=end; num++ ))
do
    is_prime $num

    if [ $? -eq 0 ]
    then
        echo "$num"
    fi
done
```
#Q11. File Type Backup System
Create a directory named backup_practice_<your_id> with the following structure:
backup_practice_<your_id>/
├── source/
├── backup/
├── scripts/
└── logs/
Inside source, create the following files:
main.c
test.py
index.html
style.css
data.txt
info.txt
error.log
image.png
photo.jpg
run.sh

Create a shell script named scripts/backup_by_type.sh that:
1. Copies all .c, .py, and .sh files into backup
2. Writes the copied file names into logs/backup.log
3. Counts how many files were copied
4. Displays Backup completed with total copied file count

## code
```
#!/bin/bash

source_dir="../source"
backup_dir="../backup"
log_file="../logs/backup.log"

> "$log_file"

count=0

for file in "$source_dir"/*.c "$source_dir"/*.py "$source_dir"/*.sh
do
    if [ -f "$file" ]
    then
        cp "$file" "$backup_dir/"
        echo "$(basename "$file")" >> "$log_file"
        count=$((count + 1))
    fi
done

echo "Backup completed with total copied file count: $count"
```

Q12. Remove Empty Files
Create a directory named empty_file_lab_<your_id> with a folder named files.
Inside files, create the following files:
a.txt
b.txt
c.txt
d.log
e.sh

Add some text only into a.txt and d.log. Keep the other files empty.
Create a shell script named remove_empty.sh that:
1. Checks each file using a loop
2. Deletes only empty files
3. Saves deleted file names into deleted_empty.log
4. Displays the remaining files

##code
```
#!/bin/bash

cd files

log_file="../deleted_empty.log"
> "$log_file"

for file in *
do
    if [ -f "$file" ]
    then
        if [ ! -s "$file" ]
        then
            echo "$file" >> "$log_file"
            rm "$file"
        fi
    fi
done

echo "Remaining files:"
ls
```
#Q13. Count Words from a File
Create a directory named word_lab_<your_id> with folders:
data/
reports/
scripts/
Inside data, create a file named paragraph.txt with any 5 lines of text.
Create a shell script named scripts/word_report.sh that:
1. Counts total lines
2. Counts total words
3. Counts total characters
4. Saves the result into reports/word_report.txt
5. Displays the report

## code
```
#!/bin/bash

input_file="../data/paragraph.txt"
output_file="../reports/word_report.txt"

{
echo "Word Report"
echo "----------------"
echo "Total Lines: $(wc -l < "$input_file")"
echo "Total Words: $(wc -w < "$input_file")"
echo "Total Characters: $(wc -c < "$input_file")"
} > "$output_file"

cat "$output_file"
```

#Q14. Array Sum of Even Positions

Create a shell script named even_position_sum.sh.

The script should:
1. Take 6 numbers as input
2. Store them in an array
3. Add only the numbers stored at even positions

4. Add only the numbers stored at odd positions
5. Display both sums separately

Note: You may consider the first element as position 1.

## code
```
#!/bin/bash

array=()

for (( i=0; i<6; i++ ))
do
    read -p "Enter number: " num
    array[i]=$num
done

even_sum=0
odd_sum=0

for (( i=0; i<6; i++ ))
do
    pos=$((i+1))

    if (( pos % 2 == 0 ))
    then
        even_sum=$((even_sum + array[i]))
    else
        odd_sum=$((odd_sum + array[i]))
    fi
done

echo "Even position sum: $even_sum"
echo "Odd position sum: $odd_sum"
```

#Q15. Reverse Array Elements
Create a shell script named reverse_array.sh.

The script should:
1. Take 5 numbers as input
2. Store them in an array
3. Display the original array
4. Display the array in reverse order

## code
```
#!/bin/bash

array=()

for (( i=0; i<5; i++ ))
do
    read -p "Enter number: " num
    array[i]=$num
done

echo "Original array: ${array[*]}"

echo "Reversed array:"

for (( i=4; i>=0; i-- ))
do
    echo -n "${array[i]} "
done

echo ""
```
# Q16. String Case Converter
Create a shell script named case_converter.sh.

The script should:
1. Ask the user to enter a word
2. Convert the word to uppercase
3. Convert the word to lowercase
4. Display both results

```
#!/bin/bash

read -p "Enter a word: " s

upper=${s^^}
lower=${s,,}

echo "Uppercase: $upper"
echo "Lowercase: $lower"
```

#Q17. Count Specific Character in String
Create a shell script named char_count.sh.

The script should:
1. Ask the user to enter a string
2. Ask the user to enter one character
3. Count how many times that character appears in the string
4. Display the count

```
#!/bin/bash

read -p "Enter a string: " s
read -p "Enter a character: " ch

count=0
len=${#s}

for (( i=0; i<len; i++ ))
do
    if [ "${s:$i:1}" == "$ch" ]
    then
        count=$((count + 1))
    fi
done

echo "Count: $count"
```

# Q18. Product Stock File Practice
Create a directory named stock_lab_<your_id> with folders:

data/
reports/
scripts/

Inside data, create a file named stock.txt with the following content:

ID Product Category Quantity
501 Pen Stationery 50
502 Pencil Stationery 70
503 Mouse Electronics 15
504 Keyboard Electronics 20
505 Chair Furniture 10
506 Table Furniture 8
507 Monitor Electronics 12
508 Notebook Stationery 40

Create a shell script named scripts/category_stock.sh that:
1. Asks the user to enter a category name
2. Searches matching products using grep

3. Saves the matching records into reports/<category>_stock.txt
4. Displays the number of matching products
5. Displays No product found if there is no match

```
#!/bin/bash

read -p "Enter category: " cat

input_file="../data/stock.txt"
output_file="../reports/${cat}_stock.txt"

result=$(grep "$cat" "$input_file")

if [ -z "$result" ]
then
    echo "No product found"
else
    echo "$result" > "$output_file"
    echo "$result"
    echo "Total products: $(echo "$result" | wc -l)"
fi
```

#Q19. Move Large Text Files
Create a directory named size_lab_<your_id> with folders:

files/
large/
small/
scripts/

Inside files, create 5 text files. Add more than 3 lines into some files and only 1 line into others.

Create a shell script named scripts/move_by_lines.sh that:
1. Checks each .txt file inside files
2. Moves files with more than 3 lines into large
3. Moves files with 3 or fewer lines into small
4. Displays the contents of both folders

```
#!/bin/bash

cd files

for file in *.txt
do
    lines=$(wc -l < "$file")

    if (( lines > 3 ))
    then
        mv "$file" ../large/
    else
        mv "$file" ../small/
    fi
done

echo "Large folder:"
ls ../large/

echo "Small folder:"
ls ../small/
```

#Q20. Factorial Using Function
Create a shell script named factorial_function.sh.

The script should:
1. Ask the user to enter a number
2. Define a function named factorial
3. Calculate the factorial using a loop

4. Display the result

Example:
Input: 5
Output: Factorial of 5 is 120

```
#!/bin/bash

factorial() {
    n=$1
    result=1

    for (( i=1; i<=n; i++ ))
    do
        result=$((result * i))
    done

    echo $result
}

read -p "Enter a number: " num

ans=$(factorial $num)

echo "Factorial of $num is $ans"
```





