i=0;
while true ;
do
    echo "$i second"
    ps -ef
    i=$(( $i+1 ));
    sleep 1
done

