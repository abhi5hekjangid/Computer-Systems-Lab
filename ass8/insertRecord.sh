#2111CS01 Abhishek Jangid 
#27-03-22
#used to insert record
file="$1"
#checking what to do means input only one or multiple
if [ "$#" -gt 2 ];
then
	shift
fi

#taking input via flags
while getopts r:n:c: flag
do
    case "${flag}" in
        r) rn=${OPTARG}
				while read -r fileName; do
				# reading each line
					read -a line <<< $fileName
					
					if [ "${line[0]}" == "$rn" ];
					then 
						echo "ROLLNO already exists."
						exit 1
					fi
				done < $file
		 ;;
        n) name=${OPTARG}
			if [[ $name =~ ^[+-]?[0-9]+$ ]]; then
				echo "Name should not be an integer."
				exit 1
			fi
			;;
        c) cpi=${OPTARG};;
    esac
done

if [ "$#" -gt 2 ];
then
	echo "$rn $name $cpi" >> $file
	echo "RECORDS ADDED TO '$file' relation  'RollNo' $rn, 'Name' $name and 'CPI' $cpi"
fi

if [ "$#" -le 2 ];
then
	#taking multiple inputs
	for num in $(seq 1 $2)
		do
			echo "Record $num"
			echo "ENTER VALUES FOR RollNo: "
			read rn
				while read -r fileName; do
				# reading each line
					read -a line <<< $fileName
					
					if [ "${line[0]}" == "$rn" ];
					then 
						echo "ROLLNO already exists."
						exit 1
					fi
				done < $file

			echo "ENTER VALUES FOR Name: "
			read name
			if [[ $name =~ ^[+-]?[0-9]+$ ]]; then
				echo "Name should not be an integer."
				exit 1
			fi
			echo "ENTER VALUES FOR CPI: "
			read cpi
			echo "$rn $name $cpi" >> $file
		done
	echo "$num RECORDS ADDED TO '$file' relation"	
fi

exit 0