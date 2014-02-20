#!/bin/bash
set -xu

files="/home/keiohigh2nd/local_tool/sample_images/adj_images/normal/*"
pre="/home/keiohigh2nd/local_tool/sample_images/quanti/DM/1.jpg"
i=0

for filepath in ${files}
do
  python2.7 get_desc.py ${filepath}
  i=`expr $i + 1`
done

echo done
