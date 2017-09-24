#!/bin/bash

export BOOK_DIR=../articles

# 書籍PDFファイル名、書籍タイトル、ID開始番号をここで調整
# これらは、それぞれ空白で区切って複数指定可
export BOOKS=("C89-FirstStepReVIEW-v2.pdf")
export TITLES=("技術書をかこう！～はじめてのRe:VIEW～")
export IDSTARTS=(10000)

# Dropbox APIのaccess token
export TOKEN="xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"

export DESTAPPDIR=~/Dropbox/Apps/MyFirstStepReVIEW-v2/
# これらは、それぞれ空白で区切って複数指定可
export FOLDERS=("Book1") # 'Book1' ディレクトリ（複数冊ある時は別々のフォルダが良い）
export COPIES=(10) # 10部

qrencode --help &> /dev/null || exit 1

mkdir -p csv
mkdir -p json
mkdir -p qrimages

book=0
for BOOK in $BOOKS
do
	title=${TITLES[$book]}
	folder=${FOLDERS[$book]}
	copies=${COPIES[$book]}
	id=${IDSTARTS[$book]}
	echo $((id++)) > /dev/null

	# <step1>
	# URLに含めるランダム文字列を生成（書籍ごと。 head -n 部数）
	cat /dev/urandom | openssl enc -base64 | tr -cd  'a-zA-Z0-9' | fold -w 64 | head -n $copies > rand.txt
	# 念のため重複がないことを確認
	cat rand.txt|sort|uniq|wc -l
	# Dropboxファイルを作成
	rm -rf $DESTAPPDIR/$folder/
	mkdir -p $DESTAPPDIR/$folder/
	for f in $(cat rand.txt)
	do
		cp $BOOK_DIR/$BOOK $DESTAPPDIR/$folder/$f-$BOOK
	done
	echo " $DESTAPPDIR/$folder にファイルを $copies 件コピーしました。コピー処理とDropboxへのアップロードが完了してから、ENTERを押して処理を続行してください。"
	read line
	
	# </step1>
	
	# <step2>
	pushd .
	cd $DESTAPPDIR/$folder/
	for f in $(ls *)
	do
		echo $f
		curl -X POST https://api.dropboxapi.com/2/sharing/create_shared_link \
    --header "Authorization: Bearer $TOKEN" \
    --header "Content-Type: application/json" \
    --data "{\"path\": \"/$folder/$f\",\"short_url\": false}"
		echo ""
	done
	popd
	# </step2>

	# <step3>
	curl -X POST https://api.dropboxapi.com/2/sharing/list_shared_links \
    --header "Authorization: Bearer $TOKEN" \
    --header "Content-Type: application/json" \
    --data "{}" \
    -o json/shared_links.json
    # </step3>
    
    # <step4>
    node get_ids.js $BOOK
    # </step4>

	rm -f csv/urls_$BOOK.csv
	for f in $(cat csv/$BOOK.csvfrag)
	do
	  echo "$id,$f" >> csv/urls_$BOOK.csv
	  : $((id++))
	done

	rm -f json/urls_$BOOK.json
	echo "[" > json/urls_$BOOK.json

	for i in $(cat csv/urls_$BOOK.csv | xargs -n 1 )
	do
		# QRコード画像を生成
		qrencode -o qrimages/$(echo $i | cut -d, -f1).png $(echo $i | cut -d, -f2)
		# JSONレコードを生成
		echo "{\"id\": \"$(echo $i | cut -d, -f1)\", \"url\": \"$(echo $i | cut -d, -f2)\", \"title\": \"$title\"}," >> json/urls_$BOOK.json
	done

	echo "{}]" >> json/urls_$BOOK.json


	echo $((book++)) > /dev/null
done
