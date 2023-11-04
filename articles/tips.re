= 役に立つ豆知識

技術書を作る際に詰まる部分をまとめました。
知らなければたどり着かない知識や、ちょっとした工夫など便利なテクニックを紹介します。

== 推奨するディレクトリ構成

#@# NOTE author:vvakame

TechBoosterが推奨するディレクトリ構成を述べておきます。
要点は次のとおりです。
具体的には@<list>{directory}です。

 * リポジトリのトップレベルにはファイルをあまり散らかさない
 * 複数人で執筆したときにそファイルが混ざったり邪魔になったりしないようにする
 * 著者全員で利用するRe:VIEWのバージョンを固定する
 * ビルド手順を統一できるタスクランナーを使う（TechBoosterの場合、Node.js+npm-scripts）

//list[directory][ディレクトリ構成]{
  ├── README.md
  ├── setup.sh              （執筆前にgemやnpmのインストールを行うスクリプト）
  ├── Gemfile               （bundler経由でRe:VIEWを利用するための設定ファイル）
  ├── Gemfile.lock          （ライブラリのバージョンをロックする）
  ├── package.json          （gruntを利用するためのnpm用設定ファイル）
  ├── npm-shrinkwrap.json   （ライブラリのバージョンをロックする）
  ├── Gruntfile.js          （gruntの動作設定ファイル）
  ├── prh-rules             （prhのリポジトリ横断の共通設定）
  ├── articles
  │   ├── catalog.yml       （Re:VIEW用 章立ての設定ファイル）
  │   ├── config.yml        （Re:VIEW用 本を生成するときのメタデータ記述ファイル）
  │   ├── prh.yml           （language-review用校正設定ファイル）
  │   ├── preface.re
  │   ├── foo.re
  │   ├── bar.re
  │   ├── contributors.re
  │   ├── images
  │   │   ├── foo           （foo.re用）
  │   │   │   └── description-of-foo.png
  │   │   └── bar           （bar.re用）
  │   │       └── bar-introduction.png
  │   ├── layouts           （存在しない場合もある）
  │   │   └── 省略
  │   └── sty               （存在しない場合もある）
  │       └── 省略
  └── code                  （サンプルコード置き場）
      ├── foo               （foo.re用）
      │   └── sample.js
      └── bar               （bar.re用）
          └── flush.js
//}

原稿は@<tt>{articles}ディレクトリに、サンプルコードは@<tt>{code}ディレクトリに入れています。
@<tt>{articles/images}や@<tt>{code}の中は、原稿の章ごとに@<tt>{.re}ファイル名と同名のディレクトリを用意し、その中で活動します。

原稿のファイル名は、わかりやすいのが一番！ということで複数名で執筆する場合、筆者の名前にしてしまう場合があります。
@<tt>{vvakame.re}というファイル名にしてしまえば、レビューを行ったりビルドエラーが出ていたりと問題が発生したとき連絡する人がわかりやすいという発想です。


== 紙面レイアウトを変更する

印刷所へ入稿する原稿を制作しているとRe:VIEWが標準で用意している構成そのものを変更する必要に迫られるときがあります。
Re:VIEWではPDFを出力するためにLaTeXを利用しています。そのため、レイアウトの変更にはLaTeXの知識が必要です。

@<tt>{config.yml}の設定値を変更したい場合@<hd>{configure|layout}を参照してください。既存のスタイルとお勧めの組み合わせを紹介しています。きっと欲しいパラメータが見つかるでしょう。

さらにRe:VIEWが出力するLaTeXソースファイルの構成を変更する拡張例としてRe:VIEWテンプレートリポジトリの内容を紹介します。
テンプレートリポジトリでは@<tt>{articles}ディレクトリの下に@<tt>{layouts/config-local.tex.erb}と@<tt>{sty/techbooster-doujin-base.sty}を置いて
@<tt>{config.yml}パラメータにTechBooster独自の設定を追加しています。
この独自設定の内容は、表紙および裏表紙を実寸ではなく仕上がりサイズにリサイズするというものです。なにか設定項目を追加する際のよい手本になるはずです。

Re:VIEWでの紙面レイアウトやデザインを自分でカスタマイズしたいと感じましたか？そんな方のために開発者ガイドラインがあります。

 : review-jsbook.clsの基本版面設計
   @<href>{https://review-knowledge-ja.readthedocs.io/ja/latest/latex/paper-layout.html}
 : Re:VIEW 3からのLaTeX処理
   @<href>{https://review-knowledge-ja.readthedocs.io/ja/latest/latex/review3-latex.html}

カスタマイズにあたってはリストや紙面の飾りといった影響範囲の小さいものから試していくと満足度が得やすいです。
そこまで複雑なことがしたいわけじゃなくて行あたりの文字数やフォントサイズを変えたい場合@<fn>{new_layout}にはRe:VIEWの初期設定コマンド（@<code>{review-init -w プロジェクト名}）がGUI上で取り組めて便利です。

//footnote[new_layout][@<href>{https://review-knowledge-ja.readthedocs.io/ja/latest/faq/faq-tex.html#5da91055a04a506c0d01a78b804b70a3}]

== 余白を調節する

PDFで出力するページの余白を指定するには@<tt>{config.yml}の@<code>{texdocumentclass}項目を調整します。
前述の@<code>{review-init -w プロジェクト名}で調整することも可能ですが、すでにあるプロジェクトには適用できないため@<code>{texdocumentclass}を手でコピーするなど
ひと工夫してください。

//emlist[config.ymlでの余白設定]{
texstyle: ["reviewmacro"]
texdocumentclass: ["review-jsbook", "media=print,paper=b5,serial_pagination=true,
  hiddenfolio=nikko-pc,openany,fontsize=10pt,baselineskip=15.4pt,line_length=40zw,
  number_of_lines=35,head_space=30mm,headsep=10mm,headheight=5mm,footskip=10mm"]
//}

リストはテンプレートリポジトリの標準設定です。@<code>{head_space=30mm}は上部（天）の余白が30mmと設定しています。
ここで指定できる単位は@<code>{cm}、@<code>{mm}の他にもLaTeXでサポートされている@<code>{in}、@<code>{pt}、@<code>{em/ex}、@<code>{zw/zh}、@<code>{Q}などがあります。

== 表紙をつける
電子書籍用のPDFファイルに表紙を含めたい場合は@<tt>{config.yml}を次のとおり変更してください。
大事な部分だけ抜粋して紹介します。

//image[coverimage][電子書籍に表紙を設定する]{
//}

//emlist[config.ymlで表紙を設定する]{
# 表紙にするファイル。ファイル名を指定すると表紙として入る （PDFMaker向けにはLaTeXソース断片、EPUBMaker向けにはHTMLファイル）
# cover: null
#
# 表紙に配置し、書籍の影絵にも利用する画像ファイル。省略した場合はnull （画像を使わない）。画像ディレクトリ内に置いてもディレクトリ名は不要（例: cover.jpg）
# PDFMaker 固有の表紙設定は pdfmaker セクション内で上書き可能
coverimage: cover.jpg

# B5の設定（10pt 40文字×35行） - 紙版
# texdocumentclass: ["review-jsbook", "media=print,paper=b5,serial_pagi...（省略）
# B5の設定（10pt 40文字×35行） - 電子版
texdocumentclass: ["review-jsbook", "media=ebook,paper=b5,serial_pagination=true,
  openany,fontsize=10pt,baselineskip=15.4pt,line_length=40zw,number_of_...（省略）

# TechBooster Re:VIEW-Template独自設定
techbooster:
  # 表紙および裏表紙を実寸ではなく仕上がりサイズにリサイズするか
  # texdocumentclassでcover_fit_page=trueを付けるのと同じ
  cover_fit_page: true
  # 裏表紙画像指定。画像はimages/から探索される
  # backcoverimage: backcover.jpg
//}

@<code>{coverimage}へは表紙画像を指定します。プロジェクトの設定ファイルが@<tt>{articles/config.yml}に位置している場合には
@<tt>{articles/images/cover.jpg}へ配置します。

カバーとなる表紙画像は@<code>{texdocumentclass}項目のメディア設定が電子書籍であるとき（@<code>{media=ebook}）に出力します。@<code>{media=print}の場合には無視します。
もし最初のページに表紙画像が表示されないときはメディア設定を再確認してください。

@<code>{cover_fit_page}項目は用紙サイズにあわせて画像をリサイズします。表示品質に影響するためデフォルトでは無効化していますが、
電子版の判型に合わせて画像を作成するのも手間ということでTechBoosterで独自拡張している設定項目です。
電子書籍にも表紙があったほうが華やかでいいですね。

== 大扉を変える
Re:VIEWをつかっていて@<kw>{大扉,タイトルページ}が気になるときがあります。大扉は本を開いた最初に本のタイトルや著者名がかかれたページです。

//image[hontobira_subtitle][大扉にサブタイトルをつけた例]{
//}

改行位置であったりタイトルが入りきらなかったりと気になる理由はさまざまですが、ここでは回避する設定をふたつ紹介します。

=== サブタイトルを使いたいとき
書名が長くて改行したいときやサブタイトルが入っている場合は@<tt>{config.yml}を次のとおり変更してください。

//emlist[config.ymlで大扉にサブタイトルを追加する]{
# 書名
booktitle: {name: "技術書をかこう！", file-as: "ギジュツショヲカコウ"}
subtitle: {name: "～はじめてのRe:VIEW～", file-as: "ハジメテノレビュー"}
//}

@<code>{subtitle}項目は正式なものではありませんが、Re:VIEWテンプレートリポジトリに含まれている自動生成の大扉ページに入っているので実は使えます。
タイトルに比べて少し小さく表示され、収まりもいいので改行を避けたいときは使いやすい方法です。

=== 完全に差し替えたいとき
大扉をオリジナルで作成したいときはTeXで書くか別の画像ファイルまたはPDFファイルなどで差し替えられます。
@<tt>{config.yml}を次のとおり変更してください。

//emlist[config.ymlで大扉を指定する]{
# 表紙の後に大扉ページを作成するか。省略した場合はtrue （作成する）
titlepage: true
#
# 自動生成される大扉ページを上書きするファイル。ファイル名を指定すると大扉として入る （PDFMaker向けにはLaTeXソース断片、EPUBMaker向けにはHTMLファイル）
titlefile: mytitle.tex
//}

@<code>{titlefile}項目に@<code>{mytitle.tex}を指定します。このときプロジェクトの設定ファイルが@<tt>{articles/config.yml}に位置している場合には
@<tt>{articles/mytitle.tex}へ配置します。

TeXファイルの中身は自由です。ここではRe:VIEWが提供している便利マクロを使って画像やPDFファイルで差し替えます。

//emlist[mytitle.texの作成例]{
\begin{titlepage}
    \thispagestyle{empty}
    \includefullpagegraphics{images/hontobira.jpg}
\end{titlepage}\clearpage
//}

@<code>{\includefullpagegraphics}マクロでは@<tt>{hontobira.jpg}ファイルを白ページに中心寄せで読み込んでいます。
このとき画像ファイルは@<tt>{articles/images}ディレクトリ内に配置してください。サンプルでは@<tt>{.jpg}ファイルを使っていますがPDFファイルを指定することもできます。
判型を合わせて作り込むとより美しく満足度が高いものが仕上がります。


===[column] レイアウトを変更する楽しみ

ヘッダやフッタを変えたい、ノンブルを隠したい（隠しノンブルと呼びます）、コードハイライトがついたもっとイケているリスト表示にしたいなど
紙面に凝ってくるとレイアウトへの要望がでてきます。紙面作りを楽しんでいる証拠ともいえるでしょう。

Re:VIEWでのレイアウトに関する部分の多くはLaTeXの知識を必要とします。
自由度が高い一方、独特の記法への馴染みの薄さやパッケージ、環境の依存関係などカスタマイズが困難なため入門を目的とする本書では触れていません。

そんなあなたには、奥村晴彦氏の「LATEX2e 美文書作成入門」@<fn>{book_latex2e}がお勧めです。
深淵を覗けますよ！

===[/column]

//footnote[book_latex2e][「LATEX2e美文書作成入門」 @<href>{https://www.amazon.co.jp/dp/4774187054/} - 奥村晴彦著 技術評論社刊]

== プリプロセッサ命令

Re:VIEWでは最終的な見た目に影響する記法とは別に、外部の情報を@<tt>{.re}ファイルに反映する@<kw>{プリプロセッサ命令}があります。
プリプロセッサ命令を使うことで、外部ファイルとしているサンプルコードを自動で@<tt>{.re}ファイル内に反映できます。

プリプロセッサ命令を処理するには@<code>{review-preproc}コマンド@<fn>{preproc-doc}を使用します。
@<code>{review-preproc}コマンドは、PDFのビルド時に自動で実行するようにしておくと便利です。
@<hd>{tips|config_task_runner}を参照してください。

//footnote[preproc-doc][@<href>{https://github.com/kmuto/review/blob/master/doc/preproc.ja.md}]

プリプロセッサ命令は、あくまで@<tt>{.re}ファイルの一部を書き換えるだけです。
最終的に@<tt>{.re}ファイルの内容がビルドされることに変わりはありません。

=== ファイルの内容を読み込む

#@# prh:disable
@<code>{mapfile}命令は、外部ファイルの内容をすべて読み込みます。
外部ファイルを読み込む箇所に@<code>{#@mapfile(file_name)}と読み込み範囲の終了を示す@<code>{#@end}を記述します。
@<code>{review-preproc}コマンドは@<code>{#@mapfile(file_name)}と@<code>{#@end}の間にファイル@<code>{file_name}を読み込みます。

たとえばサンプルコード@<tt>{foo.rb}を読み込む場合、@<list>{sample_mapfile_before}のように記述します。

#@# prh:disable
//list[sample_mapfile_before][コンパイル前のmapfile記述]{
 //list[sample_code][サンプルコード]{
 #@mapfile(foo.rb)
 #@end
 //}
//}

@<list>{sample_mapfile_before}は@<code>{review-preproc}コマンドの処理後に@<list>{sample_mapfile_after}のようになります。
Re:VIEWは@<code>{#@〜}の行をPDFやHTMLファイルなどの最終的な成果物には出力せず、@<tt>{foo.rb}の内容だけを出力します。

#@# prh:disable
//list[sample_mapfile_after][コンパイル後のmapfile記述]{
 //list[sample_code][サンプルコード]{
 #@mapfile(foo.rb)
 puts "foo"
 #@end
 //}
//}

=== タブ文字をスペースに置換するtabwidthオプション

@<code>{review-preproc}コマンドは@<code>{tabwidth}オプションを使うと、
プリプロセッサ命令で読み込むファイルのタブ文字を任意の数のスペースに置換します。

紙面の都合上、TechBoosterではサンプルコードのインデントは２スペースとしています。
しかし、サンプルコードを最初から２スペースのインデントで書くというのはあまりやりたくありません。
タブ文字でインデントしておけば原稿に反映する際に自動でインデントの文字幅を置換できます。
サンプルコードを編集するエディタ上ではタブ文字を好みの幅で表示しましょう。

@<code>{tabwidth}オプションは@<code>{--tabwidth=WIDTH}という形式で指定します。
たとえば、@<tt>{sample.re}に対して@<code>{review-preproc}コマンドを実行しタブ文字を２スペースに置換するには、次のようにします。

//cmd{
$ review-preproc -r --tabwidth=2 sample.re
//}

このオプションが効くのは、あくまでプリプロセッサ命令で読み込むファイルの内容のみです。
@<code>{mapfile}などを使わず@<code>{list}ブロック内に直接コードを書いている場合は、
@<code>{review-compile}コマンドの@<code>{tabwidth}オプションを使えば、出力結果のインデントを調整できます。

=== ファイルの内容の一部を読み込む

@<code>{maprange}命令は、外部ファイルの一部を読み込みます。
ただし、外部のファイル側に読み込み範囲を示すプリプロセッサ命令を記述しておく必要があります。

#@# prh:disable
@<code>{#@range_begin(range_name)}と@<code>{#@range_end(range_name)}で範囲を括ります。
@<list>{sample_maprange_source}は、@<code>{#@range_begin(range_name)}と@<code>{#@range_end(range_name)}を記述した例です。

#@# prh:disable
//list[sample_maprange_source][maprangeで読み込むsrc.txt]{
 ここは読み込みません。
 #@range_begin(sample)
 ここを読み込みます。
 #@range_end(sample)
 ここは読み込みません。
//}

#@# prh:disable
@<list>{sample_maprange_source}で指定した範囲を読み込むには、.reファイルに@<list>{sample_maprange_before}のように記述します。
また、@<code>{#@maprange(...)}は@<code>{#@map(...)}と記述しても動作します。

#@# prh:disable
//list[sample_maprange_before][コンパイル前のmaprange記述]{
 //list[sample_code][サンプルコード]{
 #@maprange(src.txt, sample)
 #@end
 //}
//}

@<list>{sample_maprange_before}は@<code>{review-preproc}コマンドの処理後に@<list>{sample_maprange_after}のようになります。

#@# prh:disable
//list[sample_maprange_after][コンパイル後のmaprage]{
 //list[sample_code][サンプルコード]{
 #@maprange(src.txt, sample)
 ここを読み込みます。
 #@end
 //}
//}

#@# #@@maprange 記法についても言及したい https://github.com/kmuto/review/blob/master/doc/preproc.ja.md#maprange-1
#@# mhidaka 言及したっぽい

=== 外部コマンドの結果を読み込む

@<code>{mapoutput}命令は、外部コマンドの結果を読み込みます。
この命令はRe:VIEWの記法の枠内に囚われず、任意の処理の結果を@<tt>{.re}ファイルに埋め込めます。
しかし、あくまでコンパイルするマシンにインストールしているコマンドを使用するため、複数人で執筆する場合は注意が必要です。

たとえば、筆者の環境のJavaバージョンを自動で埋め込む場合は@<list>{sample_mapoutput_before}のように記述します。

#@# prh:disable
//list[sample_mapoutput_before][java -version]{
 #@mapoutput(java -version 2>&1)
 #@end
//}

@<list>{sample_mapoutput_before}はコンパイル後に@<list>{sample_mapoutput_after}のようになります。

#@# prh:disable
//list[sample_mapoutput_after][java -version]{
 #@mapoutput(java -version 2>&1)
 java version "1.8.0_131"
 Java(TM) SE Runtime Environment (build 1.8.0_131-b11)
 Java HotSpot(TM) 64-Bit Server VM (build 25.131-b11, mixed mode)
 #@end
//}


=={config_task_runner} タスクランナーの設定

#@# NOTE author:vvakame

複数人で執筆する場合、何らかの統一された手順でのビルド手順が必要です。
TechBoosterではNode.js+npm-scripts（裏はgrunt）を利用しています。
この構成になっているのは、プロジェクト構成を担当しているvvakameが一番使い慣れているからという理由が大きいです。

新規に書き起こすのであれば、執筆者があまり導入の手間をかけなくてもよいものを選ぶのがよいでしょう。
候補としては、RubyはRe:VIEWのためにすでに入っているはずなのでRuby上で動作するrakeを使うか、いろいろなOSや環境で導入済みである場合の多いJavaやGradle@<fn>{why-gradle}の組み合わせがよいかもしれません。

//footnote[why-gradle][GradleにはGradle Wrapperという仕組みがあり、Gradleの実行環境を別途用意する必要がないため便利]


タスクランナーが行うべき作業は少ないです。

 * 古い生成ファイルを消す
 * @<code>{review-preproc}コマンドを実行する
 * 各ターゲット向けのビルド用コマンドを実行する

これだけです。ひとつひとつ、どういうコマンドと等価な処理をしていけばよいかを解説します。

 * 古い生成ファイルを消す（消さないとエラーになる場合がある）

最低限必要なのは次のコマンドと同様の動作です。

#@# prh:disable
//emlist{
rm -rf articles/C89-FirstStepReVIEW-v2-pdf/ \
       articles/*.pdf  \
       articles/*.epub \
       articles/*.html \
       articles/*.xml  \
       articles/*.txt
//}

#@# prh:disable
それぞれ@<code>{--debug}オプション付きでpdfをビルドしたときのtmpディレクトリ、pdf、epub、html、idgxml（Adobe InDesign用XML）、text生成時に作成される一時ファイルまたは最終出力ファイルです。
一番最初の行のC89-FirstStepReVIEW-v2-pdf部分は@<tt>{articles/config.yml}の@<code>{bookname}の設定により変化します。

 * @<code>{review-preproc}コマンドを実行する

最低限必要なのは次のコマンドの実行です。

//emlist{
# articlesディレクトリ内で実行する想定
$ review-preproc -r --tabwidth=2 *.re
//}

@<code>{review-preproc}コマンドはRe:VIEWの仕組みの中で、もっとも便利な、愛すべきコマンドといえます。
@<code>{review-preproc}コマンドは文書中に埋め込まれたpragmaを処理し、サンプルコードを文書中に展開したり指定のコマンドの実行結果を文書中に展開してくれます。
C言語のマクロとだいたい同じものだと思えばよいでしょう。

TechBoosterでは文書にソースコードを貼りこむとき、インデントは2スペースと整理しています。
このため4スペース派の人はサンプルコードではタブを使うようにして、エディタ上では1タブ＝4スペースで作業し、文書中に貼りこむときにタブを2スペースに変換するとよいでしょう。

詳細は@<chapref>{review-introduction}に譲ります。

 * 各ターゲット向けのビルド用コマンドを実行する

最低限必要なのは次のコマンドの実行です。

//emlist{
# すべて、articlesディレクトリ内で実行する想定
# textの生成
$ review-compile --all --target=text
# htmlの生成
$ review-compile --all --target=html --stylesheet=style.css --chapterlink
# latexの生成
$ review-compile --all --target=latex --footnotetext
# idgxmlの生成
$ review-compile --all --target=idgxml
# pdfの生成
$ review-pdfmaker config.yml
# epubの生成
$ review-epubmaker config.yml
//}

欲しい出力結果に応じて、コマンドを使い分けます。
PDF、EPUBについては利用するコマンドそのものが違うので注意します。
詳細は@<chapref>{publishing-book}を参照してください。

あとはそれぞれのターゲット向けに下準備とビルドを行うタスクを作成するだけです。

#@# prh:disable
これらを詰め込んだ、実際にTechBoosterで使っているgrunt用設定ファイルを公開しています。

#@# prh:disable
 * @<href>{https://github.com/TechBooster/C89-FirstStepReVIEW-v2/blob/master/Gruntfile.js}

Node.jsのバージョンといった動作条件はリポジトリのメンテナンスなどで更新があります。利用前にリポジトリを確認してください。

== 関連各所の紹介
TechBoosterがRe:VIEWを使っているなかで関係したお世話になっている各所を紹介します。

 * 達人出版会：Re:VIEWを使った電子書籍を扱う出版社
 * トップスタジオ：Re:VIEWによるリフロー（自動組版）を導入している制作会社
 * 日光企画：お世話になっている印刷所

 ありがとう！そしてありがとう！！

== 品質を高めるためのチェックポイント

限られた時間のなかで可能な限り品質を確保するポイントをリスト形式で紹介します。

 * 企画は書きたいことを選ぶ（モチベーション維持）
 * 一人でかかない（共同執筆がお勧め）
 * 執筆時点は早めの締め切りを設定する（こうしておくと致命傷で済む）
 * レビューを実施する（読者の視点を作り出す）
 * 紙面を@<code>{=}や@<code>{*}、@<code>{@}で検索する（文法ミスを見つけるため）
 * 記号などの文字化け探し（TeX、フォントはUTF-8対応しているとは限らない）
 * 紙面のはみ出しチェック（TeXコンパイル時のtoo late表示の有無を確認する）

実際には何度も読みなおして文章を推敲することが一番ですが、このようなステップを意識することで
ケアレスミスを見つけられます（特にツールに不慣れな場合は有効です）。

具体的には編集（校正）フェーズでは次のように変更しました。

#@# prh:disable:本記事
 * 冗長性の排除：検証を行うことを → ～検証することを
 * 冗長性の排除：～することができます → ～できます
 * 受け身の排除：～表示される → ～表示する、表示できます
 * 重複表現の排除：必ず必要です → 必要です
 * 平易な表現：～Aが有効であることが原因で → Aが原因で
 * 事実の表現：～なります → できます
 * 指示語の排除：これそれあれ → 前後関係が明確で無いものは排除。これが示すとおり → 出力結果が示すとおり
 * 過剰な敬語：ご確認いただけると思います → 確認できます
 * 重ね言葉：～したりします → ～だったり、～したりします
 * 表現の訂正：思います → 考えます
 * 書き出し表現のチェック：本章、本節、本項 、本稿、本記事、ここでは等がある。適切なものを選んでいるか
 * リスト、図の参照 → 本文中に＠<list>{id}は～という処理です。と概要を説明してからリストに入ること。そのあと詳細な解説としておくことで驚かない
 * 表現の統一：「こと」でのGrep → 大抵は不要。～することがあります →～します
 * 表現の統一：「どうか」でのGrep → 大抵は不要。～正しいかどうか。→  検証する
 * 表現の統一：箇条書き、リストや図のキャプションが体言止めなのか、動詞で終わっているのか、統一する

また文章単体では、かかりつけの距離を確認し、読みやすく訂正しています。

//list[before][変更前]{
アプリはOSの起動やタイマーによって定期的に起動されるアプリのServiceを作成し、RecommendationパッケージのContentRecommendationを使用してNotificaitonを作成することができます。
//}
//list[after][変更後]{
アプリの作ったServiceは、OS起動時またはタイマーによって定期的に実行できます。Serviceの中では、ContentRecommendationクラスを使ってNotificationを作り、ユーザに通知可能です。
//}

== Re:VIEW記法チートシート

//indepimage[sheet-page1][][scale=0.80]
//indepimage[sheet-page2][][scale=0.80]
//indepimage[sheet-page3][][scale=0.80]
//indepimage[sheet-page4][][scale=0.80]
