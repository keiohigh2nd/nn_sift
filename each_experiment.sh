#!/bin/bash
set -xu


rm ../good_desc.txt
rm ../mal_desc.txt
rm ../query_desc.txt
rm ../classify_result_.txt
rm text.txt

python=/home/appl/bin/python2.7
files="/home/keiohigh2nd/nnfn/good_1005/*"
pre="/home/keiohigh2nd/nnfn/iet/normal/06_h.jpg"

good="/home/keiohigh2nd/nnfn/good_1005/"
mal="/home/keiohigh2nd/nnfn/mal_1005/"
python2.7 sift_sh_NBNN.py ${pre} ${mal} ${good}

rm ../query_desc.txt
for filepath in ${files}
do
  python2.7 sift_sh_NBNN_file.py ${filepath}
  g++ -O2 tab.cpp
  ./a.out
  python2.7 each_make_test_data.py ${filepath}
  python2.7 experiment_calc.py ${filepath}
  rm text.txt
  rm test_data_index.txt
  rm ../query_desc.txt
done

echo done
