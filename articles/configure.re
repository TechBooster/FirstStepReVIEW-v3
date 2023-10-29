= 設定ファイルの解説

本章ではRe:VIEWを使う上で必要な各種設定ファイルを解説します。
Re:VIEWでは書籍に関する情報を章を設定する@<tt>{catalog.yml}と書籍のメタデータを指定する@<tt>{config.yml}に集約しています。

=={catalog_yml} 目次を構成するcatalog.yml

#@# https://github.com/kmuto/review/wiki/catalog.yml
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

 : PREDEF
   前書きなど目次の前に記載するものを指定します
 : CHAPS
   本文となる各章です。並べた順番で出力します
 : APPENDIX
   付録を指定します
 : POSTDEF
   後書きを指定します

加えて@<code>{CHAPS}はネストすることで部を構成できます。
部を構成するには、@<list>{catalog_yml_nested_chaps}のように、部のタイトル名や.reファイル名の下に章のファイルを記述します。

//list[catalog_yml_nested_chaps][部を構成するCHAPSの記述]{
CHAPS:
  - "部のタイトル":
    - chapter1.re
    - chapter2.re
  - part2.re:
    - chapter.3.re
    - chapter4.re
  - chapter5.re
//}

YAMLに馴染みがないと忘れがちですが、Collection@<fn>{url_yaml_collection}にするのでコロン記号（：）を付け忘れないようにしましょう。

//footnote[url_yaml_collection][@<href>{http://www.yaml.org/spec/1.2/spec.html#id2759963}]

=={config_yml} 書籍情報を記述するconfig.yml

#@# https://github.com/kmuto/review/wiki/config.yml

Re:VIEWでは本を生成（コンパイル）するときのメタデータをYAMLで記述します。
コンパイル時の指定方法は@<chapref>{build}を参照してください。

ファイル名に決まりはありませんが慣例的にconfig.ymlとしています。
書名や奥付の内容、どの深さまで目次に含めるかなどを設定できます。

@<list>{config_yml}は本書で使っている@<tt>{config.yml}です。

//list[config_yml][config.yml]{
# review-epubmaker向けの設定ファイルの例。
# ブック名(ファイル名になるもの。ASCII範囲の文字を使用)
bookname: C89-FirstStepReVIEW-v2
# 記述言語。省略した場合はja
language: ja
# 書名
booktitle: 技術書をかこう！～はじめてのRe:VIEW～
# 著者名。「, 」で区切って複数指定できる
aut: ["TechBooster編"]
# a-edt, edt: 編集者
edt: ["mhidaka"]
# a-pbl, pbl: 出版社（発行所）
pbl: TechBooster
# 刊行日(省略した場合は実行時の日付)
date: 2017-8-11
# 発行年月。YYYY-MM-DD形式による配列指定。省略した場合はdateを使用する
history: [["2015-12-31 C89版 v1.0.0"],["2017-8-11 C92版 v2.0.0"]]
# 権利表記
rights: (C) 2017 TechBooster
# 固有IDに使用するドメイン。指定しない場合には、時刻に基づくランダムUUIDが入る
urnid: urn:uid:https://github.com/TechBooster/C89-FirstStepReVIEW-v2

# CSSファイル(配列で複数指定可)
stylesheet: ["style.css"]
# ePUBのバージョン (2か3) 省略した場合は2
epubversion: 3
# HTMLのバージョン (4か5。epubversionを3にしたときには5にする)
htmlversion: 5

# 目次として抽出する見出しレベル
toclevel: 2
# 本文でセクション番号を表示する見出しレベル
secnolevel: 2

# 本文中に目次ページを作成するか。省略した場合はnull (作成しない)
toc: true

# 表紙の後に大扉ページを作成するか。省略した場合はnull (作成しない)
titlepage: true
# 奥付を作成するか。デフォルトでは作成されない。trueを指定するとデフォルトの奥付、ファイル名を指定するとそれがcolophon.htmlとしてコピーされる
colophon: true
# ページ送りの送り方向、page-progression-directionの値("ltr"|"rtl"|"default")
direction: "ltr"

# tatsumacroは、電子書籍版の制作に利用する
texstyle: techbooster-doujin

# LaTeX用のdocumentclassを指定する
texdocumentclass: ["jsbook", "b5j,twoside,openany,uplatex"]
//}

記述できる項目は多いので、Re:VIEW公式のサンプルとWikiを参照してください。

 : サンプル
   @<href>{https://github.com/kmuto/review/blob/master/doc/sample.yml}
 : Wiki
   @<href>{https://github.com/kmuto/review/wiki/config.yml}


== 目次に表示する項目をカスタマイズする

目次として抽出する章や節の深さを変更するには、@<tt>{config.yml}の@<code>{toclevel:}項目を設定します（@<list>{toclevel}）。

//list[toclevel][抽出レベルを設定]{
toclevel: 2
//}

抽出レベルを変更すると、値に応じた深さの見出しを出力します（@<img>{toclevel2}および@<img>{toclevel3}）。

//image[toclevel2][toclevel:2を指定した場合の目次][scale=0.75]{
//}

//image[toclevel3][toclevel:3を指定した場合の目次][scale=0.75]{
//}

=={layout} デザインを変更する

PDF形式で出力する紙面のデザインは差し替え可能です。@<tt>{config.yml}の@<code>{texstyle:}項目の値を変更します（@<list>{change_layout}）。

//list[change_layout][config.ymlにてスタイルファイルを指定]{
# LaTeX用のスタイルファイル(styディレクトリ以下に置くこと)
# texstyle: reviewmacro
# tatsumacroは、電子書籍版の制作に利用する
# texstyle: tatsumacro
texstyle: techbooster-doujin
//}

Re:VIEW、または本書のリポジトリには次の3つの設定が用意されています。

 : reviewmacro
   Re:VIEWのデフォルトスタイルです。紙面にはあまり向いていません

 : tatsumacro
   電子書籍向けのスタイルです。タブレットなどで見やすいように余白やフォントサイズを調整しています

 : techbooster-doujin
   TechBooster製のスタイルです。紙面（B5サイズ）にむけて最適化しています

印刷が前提の場合、特にこだわりがなければ@<code>{techbooster-doujin}を利用してください。もちろん独自のスタイルを作ることも可能です。

==== B5サイズでのお勧め設定

//emlist[config.ymlの印刷用設定]{
texstyle: techbooster-doujin
texdocumentclass: ["jsbook", "b5j,twoside,openany,uplatex"]
//}

==== 電子書籍（PDF）でのお勧め設定

//emlist[config.ymlの電子書籍用設定]{
texstyle: tatsumacro
texdocumentclass: ["jsbook", "oneside,14pt,uplatex"]
//}

== サイズを変更する

PDF形式で出力するページサイズを指定するには@<tt>{config.yml}の@<code>{textdocumentclass:}項目の２番目の値を設定します（@<list>{change_pagesize}）。

この設定は、LaTeXにおけるドキュメントクラスのオプションに該当します。複数のオプションがある場合は、カンマで区切って列挙します。
技術書であればb5jサイズが標準的です。

//list[change_pagesize][config.ymlにてページサイズをb5jに指定]{
texdocumentclass: ["jsbook", "b5j"]
//}

//table[papersize][設定できるページサイズ]{
値	用紙サイズ
------------
a4paper	A4
b5paper	B5
a4j	A4 JIS
a5j	A5 JIS
b5j	B5 JIS
//}

@<table>{papersize}は、@<code>{jsbook}ドキュメントクラスに設定できる代表的な用紙サイズです。
指定するドキュメントクラスによっては、設定できる値が異なる場合があるので注意してください。
