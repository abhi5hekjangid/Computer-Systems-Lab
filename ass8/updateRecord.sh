#2111CS01 Abhishek Jangid 
#27-03-22
#used to upadte record
file="$1"
n=1
shift
#finding which field to change
case "$3" in
    "RollNo" | "Rollno" | "rollno") index=0;;
    "NAME" | "Name" | "name") idx=1;;
    "CPI" | "Cpi" | "cpi") idx=2;;
esac

#taking roll no as input
while getopts r: flag
do
    case "${flag}" in
        r) rn=${OPTARG} ;;
    esac
done

count=0
#changing the values with a new value and updating the file
while read -r fileName; do
# reading each line
    read -a line <<< $fileName
    
    if [ "${line[0]}" == "$rn" ];
    then 
        if [ "$idx" == 1 ]; 
        then
            if [[ $4 =~ ^[+-]?[0-9]+$ ]]; then
				echo "Name should not be an integer."
				exit 1
			fi
            row="${line[0]} $4 ${line[2]}"

        elif [ "$idx" == 2 ]; 
        then
            row="${line[0]} ${line[1]} $4"

        else     
            row="$4 ${line[1]} ${line[2]}"
        fi
	    sed -i "s/$fileName/$row/" $file
        echo "RECORD WITH ROLLNO '$rn' IS UPDATED in '$file' table"
        count=$((count+1))
    fi
    n=$((n+1))
done < $file

if [ "$count" -lt 1 ]; then
    echo "No Record with given RollNo"
    exit 1
fi
exit 0