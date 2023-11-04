= 設定ファイルの解説

本章ではRe:VIEWを使う上で必要な各種設定ファイルを解説します。
Re:VIEWでは書籍に関する情報を章を設定する@<tt>{catalog.yml}と書籍のメタデータを指定する@<tt>{config.yml}に集約しています。

=={catalog_yml} 目次を構成するcatalog.yml

#@# https://github.com/kmuto/review/blob/master/doc/catalog.ja.md

@<tt>{catalog.yml}は章立ての設定ファイルです。
各章の.reファイルを列記し、PDFをビルドをした際の章の順序を定義します。

@<list>{catalog_yml_sample}は、@<tt>{catalog.yml}の設定例です。

//list[catalog_yml_sample][５つの章をもつcatalog.yml]{
PREDEF:
  - preface.re

CHAPS:
  - writing-book.re
  - environment.re
  - workflow.re
  - publishing-book.re
  - distribution.re

APPENDIX:
  - tips.re

POSTDEF:
  - contributors.re
//}

@<tt>{catalog.yml}の各項目の内容は次のとおりです。
CHAPSのみを必須として前書き、付録、後書きなど本を構成する構造を定義しています。

 : PREDEF
   前書きなど目次の前に記載するものを指定します
 : CHAPS
   本文となる各章です。並べた順番で出力します
 : APPENDIX
   付録を指定します
 : POSTDEF
   後書きを指定します

加えて@<code>{CHAPS}はネストすることで部を構成できます。
部を構成するには、@<list>{catalog_yml_nested_chaps}のように、部のタイトル名や@<tt>{.re}ファイル名の下に章のファイルを記述します。

//list[catalog_yml_nested_chaps][部を構成するCHAPSの記述]{
CHAPS:
  - "部のタイトル":
    - chapter1.re
    - chapter2.re
  - part2.re:
    - chapter3.re
    - chapter4.re
  - chapter5.re
//}

YAMLの記法に馴染みがないと忘れがちですがCollection@<fn>{url_yaml_collection}にするのでコロン記号（：）を付け忘れないようにしましょう。

//footnote[url_yaml_collection][@<href>{http://www.yaml.org/spec/1.2/spec.html#id2759963}]

=={config_yml} 書籍情報を記述するconfig.yml

#@# https://github.com/kmuto/review/wiki/config.yml

Re:VIEWでは本を生成（コンパイル）するときのメタデータをYAMLで記述します。
コンパイル時の指定方法は@<hd>{setup|応用編：書籍をローカル環境でビルドするには}を参照してください。

ファイル名に決まりはありませんが慣例的に@<tt>{config.yml}としています。
書名や奥付の内容、どの深さまで目次に含めるかなどを設定できます。

@<list>{config_yml}は本書で使っている@<tt>{config.yml}の一部を抜粋したものです。

#@# prh:disable
//list[config_yml][config.ymlの中身]{
# ブック名（ファイル名になるもの。ASCII範囲の文字を使用）
bookname: FirstStepReVIEW-v3
# 記述言語。省略した場合はja
language: ja
# 書名
booktitle: {name: "技術書をかこう！～はじめてのRe:VIEW～", file-as: "ギジュツショヲカコウ"}
# 著者名。「, 」で区切って複数指定できる
aut: [{name: "TechBooster編", file-as: "techboosterヘン"}]

# a-edt, edt: 編集者
edt: ["mhidaka"]
# a-pbl, pbl: 出版社（発行所）
pbl: TechBooster

# 刊行日（省略した場合は実行時の日付）
date: 2023-11-12

# 発行年月。YYYY-MM-DD形式による配列指定。省略した場合はdateを使用する
# 複数指定する場合は次のように記述する
# [["初版第1刷の日付", "初版第2刷の日付"], ["第2版第1刷の日付"]]
# 日付の後ろを空白文字で区切り、任意の文字列を置くことも可能。
history: [["2015-12-31 C89版 v1.0.0"],["2017-8-11 C92版 v2.0.0"],["2023-11-12 技術書典15版 v3.0.0"]]

# 権利表記（配列で複数指定可）
# rights: (C) 2016 Re:VIEW Developers
rights: (C) 2017-2023 TechBooster

# 固有IDに使用するドメイン。省略した場合は時刻に基づくランダムUUIDが入る
urnid: urn:uid:https://github.com/TechBooster/FirstStepReVIEW-v3

# 目次として抽出する見出しレベル
toclevel: 2
# 本文でセクション番号を表示する見出しレベル
secnolevel: 2

# 本文中に目次ページを作成するか。省略した場合はnull（作成しない）
toc: true

# 表紙に配置し、書籍の影絵にも利用する画像ファイル。省略した場合はnull（画像を使わない）。画像ディレクトリ内に置いてもディレクトリ名は不要（例: cover.jpg）
# PDFMaker 固有の表紙設定は pdfmaker セクション内で上書き可能
coverimage: cover.jpg
#
# 表紙の後に大扉ページを作成するか。省略した場合はtrue（作成する）
titlepage: true

# 奥付を作成するか。デフォルトでは作成されない。trueを指定するとデフォルトの奥付、ファイル名を指定するとそれがcolophon.htmlとしてコピーされる
# デフォルトの奥付における各項目の名前（「著　者」など）を変えたいときにはlocale.ymlで文字列を設定する（詳細はdoc/format.ja.mdを参照）
colophon: true
//}

記述できる項目は多いので、Re:VIEW公式のサンプルとWikiを参照してください。

 : サンプル
   @<href>{https://github.com/kmuto/review/blob/master/doc/config.yml.sample}
 : Wiki
   @<href>{https://github.com/kmuto/review/wiki/config.yml}


== 目次に表示する項目をカスタマイズする

目次として抽出する章や節の深さを変更するには、@<tt>{config.yml}の@<code>{toclevel}項目を設定します（@<list>{toclevel}）。

//list[toclevel][抽出レベルを設定]{
# 目次として抽出する見出しレベル
toclevel: 2
//}

抽出レベルを変更すると、値に応じた深さの見出しを出力します（@<img>{toclevel2}および@<img>{toclevel3}）。

//image[toclevel2][toclevel:2を指定した場合の目次][scale=0.85]{
//}

//image[toclevel3][toclevel:3を指定した場合の目次][scale=0.85]{
//}

=={layout} 用紙サイズやデザインを変更する

PDF形式で出力する紙面のデザインは差し替え可能です。@<tt>{config.yml}の@<code>{texstyle}項目の値を変更します（@<list>{change_layout}）。

#@# prh:disable
//list[change_layout][config.ymlにてスタイルファイルを指定]{
# LaTeX用のスタイルファイル(styディレクトリ以下に置くこと)
# texstyle: ["reviewmacro"]
//}

 : reviewmacro
   Re:VIEWのデフォルトスタイルです
 : viewermacro
   電子書籍向けのスタイルです。タブレットなどで見やすいように余白やフォントサイズを調整しています。TechBooster製のスタイルです

#@# prh:disable
ReVIEW-Templateテンプレートリポジトリまたは本書のリポジトリには次の4つの@<code>{texdocumentclass}が用意されています。

 * B5の設定（10pt 40文字×35行）- 紙版
 * B5の設定（10pt 40文字×35行）- 電子版
 * A5の設定（9pt 38文字×37行）- 紙版
 * A5の設定（9pt 38文字×37行）- 電子版

==== B5サイズでの標準設定

//emlist[config.ymlの印刷用設定]{
texstyle: ["reviewmacro"]
texdocumentclass: ["review-jsbook", "media=print,paper=b5,serial_pagination=true,
  hiddenfolio=nikko-pc,openany,fontsize=10pt,baselineskip=15.4pt,line_length=40zw,
  number_of_lines=35,head_space=30mm,headsep=10mm,headheight=5mm,footskip=10mm"]
//}

==== 電子書籍（PDF）での標準設定

//emlist[config.ymlの電子書籍用設定]{
texstyle: ["reviewmacro"]
texdocumentclass: ["review-jsbook", "media=ebook,paper=b5,serial_pagination=true,
  openany,fontsize=10pt,baselineskip=15.4pt,line_length=40zw,
  number_of_lines=35,head_space=30mm,headsep=10mm,headheight=5mm,footskip=10mm"]
//}

B5ではなく少し小さいA5にしたいなど書籍に合う用紙サイズへ変更するのであれば、これらのプリセットの利用を強く推奨します。

== スタイルにカスタマイズを加える

@<tt>{config.yml}の@<code>{textdocumentclass}はLaTeXにおけるドキュメントのクラスオプションに相当します。
複数のオプションがある場合はカンマで区切って列挙でき、ある程度のカスタマイズも可能です。

前節で触れた標準設定でも多くのクラスオプションが登場していました。たとえば出力するページサイズを指定するには@<tt>{config.yml}の@<code>{textdocumentclass}を次のようにします（@<list>{change_pagesize}）。

//list[change_pagesize][用紙サイズをB5に指定する例]{
texdocumentclass: ["review-jsbook", "paper=b5"]
//}

@<table>{papersize}は@<code>{review-jsbook}ドキュメントクラスに設定できる代表的な用紙サイズ（@<code>{paper}クラスオプション）です。
指定するドキュメントクラスによってクラスオプションで設定できる値が異なるので注意してください。

//table[papersize][設定できる用紙サイズ]{
値	用紙サイズ
------------
a4	A4
a5	A5
a6	A6
b5	JIS B5
b6	JIS B6
//}

=== review-jsbookに設定できる主な設定項目

@<code>{review-jsbook}に設定可能なクラスオプションは公式ドキュメントにまとまっています。

 * @<href>{https://github.com/kmuto/review/blob/master/templates/latex/review-jsbook/README.md}

@<table>{review-jsbook}では、どのようなカスタマイズができるのか理解しやすいものを挙げています。

//table[review-jsbook][設定できる主なクラスオプションと説明]{
オプション名	説明
------------
media	印刷用、電子用いずれかの用途
cover_fit_page	カバー画像を紙面に合わせる
paper	用紙サイズの変更
fontsize	文字サイズ
startpage	ページ開始番号。デフォルトは1
//}

Re:VIEWで利用している@<code>{review-jsbook}はドキュメントクラスは標準的な@<code>{jsbook}ドキュメントクラスを含んでいるので、一部のオプションはそのまま指定できます。
ここに@<code>{onecolumn}を指定すれば1段組の体裁、@<code>{twocolumn}であれば2段組の体裁を実現します。
ただし、このようなドキュメントの見た目に対して調整を行うにはTeXと書籍の専門知識が要求されます。

たとえば本のルールには章の始まりを左ページ（偶数）、右ページ（奇数）に固定できるというものがあります。一般人からすると改ページの位置が左右どっちにくるのかという問題自体に馴染みがありませんよね。@<code>{openany}を指定すると左右どちらからでも章を開始できる！と気づいてしまい、ページ数を減らせるから印刷代もちょっと安くなるじゃないか？と考えたとしても入稿直前の疲れたタイミングで変更することは推奨しません。期せず発生する副作用に悩まないように十分検証期間を設けるなど余裕を持って作業してください。

