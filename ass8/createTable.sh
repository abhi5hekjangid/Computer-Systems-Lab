#2111CS01 Abhishek Jangid 
#27-03-22
#used to create table
file="$1"
column="$2 $3 $4"
if [ -f "$file" ]
then
    echo "File $file creation failed,already exists"
    exit 1
fi
#inserting the columns in file
echo $column > $file
echo "NEW TABLE '$file' WITH FIELDS '$2', '$3', '$4' CREATED"
exit 0