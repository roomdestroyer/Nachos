rm -rf tmp_0
rm -rf tmp_1
ps aux|grep nachos|grep -v grep|cut -c 9-16|xargs kill -9
make
./nachos -rs 10
echo "tmp_0: "
cat tmp_0
echo "tmp_1: "
cat tmp_1
