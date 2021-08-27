#!/bin/bash

#tools フォルダ下で実行
cd `dirname $0`
# コンパイル
g++ -std=c++17 -O2 -Wall -Wextra C.cpp
g++ -std=c++17 -O2 -o judge_C.out judge_C.cpp 
#[st, en] のseed のファイルを処理する．procsはプロセス数，print_errorはxargs のエラー出力表示
st=0
en=99
procs=0
small=0
# インタラクティブ処理の関数
# ビジュアライザに通して，スコアを標準出力として取得する関数
large(){
  ./a.out < in/test_lsim_$1.txt > out/$1.txt
}
small(){
  ./a.out < in/test_ssim_$1.txt > out/$1.txt
}
eva(){
   ./judge_C.out < out/$1.txt >> score.txt 2>/dev/null
}
# xargs で関数使うための処理
export -f large
export -f small
export -f eva

#以前の処理を削除
rm -f score.txt
rm -rf out
mkdir out

# option

usage(){
  cat <<EOM
使い方：
  -s : 開始テストケース
  -e : 終了テストケース
  -P : プロセス数
ただし，開始テストケースから終了テストケースまでの入力ファイルは in/ 下に置いておいてください．
EOM

  exit 2
}

while getopts "s:e:P:S" optKey; do
  case "$optKey" in
    s)
      st=${OPTARG}
      ;;
    e)
      en=${OPTARG}
      ;;
    P)
      procs=${OPTARG}
      ;;
    S)
      small=1
      ;;
    '-h' | '--help' | *)
      usage
      ;;
  esac
done

# 並列処理
if [ $small = 0 ];
then
  seq -f '%02g' $st $en | xargs -t -n1 -P$procs -I{} bash -c "large {}"
else
  seq -f '%02g' $st $en | xargs -t -n1 -P$procs -I{} bash -c "small {}"
fi
seq -f '%02g' $st $en | xargs -t -n1 -P$procs -I{} bash -c "eva {}"
# score.txt に書き込まれたスコアの計算
python3 evaluate.py