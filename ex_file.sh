#!/bin/bash
set -xu


rm ../good_desc.txt
rm ../mal_desc.txt
rm ../query_desc.txt
rm ../classify_result_.txt
rm text.txt

python=/home/appl/bin/python2.7
files="/home/keiohigh2nd/nn_sift/data/malignant_melanoma_test/*"
pre="/home/keiohigh2nd/nnfn/iet/normal/06_h.jpg"

good="/home/keiohigh2nd/nn_sift/data/ncn_g/"
mal="/home/keiohigh2nd/nn_sift/data/malignant_melanoma/"
python2.7 sift_sh_NBNN.py ${pre} ${mal} ${good}

for filepath in ${files}
do
  python2.7 sift_sh_NBNN_file.py ${filepath}
  g++ -O2 tab.cpp
  ./a.out
  python2.7 draw_file.py ${filepath}
  rm text.txt
  rm ../query_desc.txt
done

echo done
