= 設定ファイルの解説

本章ではRe:VIEWを使う上で必要な各種設定ファイルを解説します。

=={catalog_yml} 章を設定するcatalog.yml

#@# https://github.com/kmuto/review/wiki/catalog.yml
#@# https://github.com/kmuto/review/blob/master/doc/catalog.ja.md

catalog.ymlは章立ての設定ファイルです。
各章の.reファイルを列記し、PDFをビルドをした際の章の順序を定義します。

@<list>{catalog_yml_sample}は、本書で使用している実際のcatalog.ymlです。

//list[catalog_yml_sample][catalog.yml]{
#@mapfile(catalog.yml)
PREDEF:
  - preface.re
CHAPS:
  - writing-book.re
  - setup.re
  - review-introduction.re
  - configure.re
  - build.re
  - workflow.re
  - tips.re

APPENDIX:

POSTDEF:
  - contributors.re
#@end
//}

catalog.ymlの各項目の内容は次のとおりです。

: PREDEF
  前書きなど目次の前に記載するものを指定します
: CHAPS
  本文の各章です。並べた順番で出力されます
: APPENDIX
  付録を指定します
: POSTDEF
  後書きを指定します

加えてCHAPSはネストすることで部を構成できます。
部を構成するには、@<list>{catalog_yml_nested_chaps}のように、部のタイトル名や.reファイル名の下に章のファイルを記述します。
YAMLに馴染みがないと忘れがちですが、Collection@<fn>{url_yaml_collection}にする必要があるのでコロン記号（：）を付け忘れないようにしましょう。

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

//footnote[url_yaml_collection][@<href>{http://www.yaml.org/spec/1.2/spec.html#id2759963}]

=={config_yml} メタデータを記述するconfig.yml

#@# https://github.com/kmuto/review/wiki/config.yml

Re:VIEWでは本を生成（コンパイル）する時のメタデータをYAMLで記述します。
コンパイル時の指定方法は@<chapref>{build}を参照してください。

ファイル名に決まりはありませんが慣例的にconfig.ymlとしています。
書名や奥付の内容、どの深さまで目次に含めるかなどを設定できます。

@<list>{config_yml}は本書で使っているconfig.ymlです。

//list[config_yml][config.yml]{
# review-epubmaker向けの設定ファイルの例。
# ブック名(ファイル名になるもの。ASCII範囲の文字を使用)
bookname: C89-FirstStepReVIEW-v2
# 記述言語。省略した場合はja
language: ja
# 書名
booktitle: 技術書をかこう！～はじめてのRe:VIEW～
# 固有IDに使用するドメイン。省略した場合は時刻に基づくランダムUUIDが入る
urnid: urn:uid:https://github.com/TechBooster/C89-FirstStepReVIEW-v2
# 著者名。["高橋征義", "John Doe"] のように配列を使うことで複数指定可
aut: ["TechBooster編"]
# 出版社。配列書式で複数指定可能
prt: TechBooster
# 編集者。配列書式で複数指定可能
edt: ["mhidaka"]
# 刊行日。YYYY-MM-DD形式。省略した場合は本日の日付
date: 2015-12-31
# 発行年月。YYYY-MM-DD形式による配列指定。省略した場合はdateを使用する
history: [["2015-12-31 C89版 v1.0.0"]]
# 権利表記
rights: (C) 2015 TechBooster
# CSSファイル(配列で複数指定可、yamlファイルおよびRe:VIEWファイルを置いたディレクトリにあること)
stylesheet: ["style.css"]

# ePUBのバージョン (2か3) 省略した場合は2
epubversion: 3

# 目次を作成するか。省略した場合はnull（作成しない）
toc: true

# 目次として抽出する見出しレベル。省略した場合は2
toclevel: 2
# 本文でセクション番号を表示する見出しレベル。省略した場合は2
# 採番させたくない見出しには「==[nonum]」のようにnonum指定をする
secnolevel: 2
# 表紙の後に大扉ページを作成するか。省略した場合はnull (作成しない)
titlepage: true
# 奥付を作成するか。デフォルトでは作成されない。trueを指定するとデフォルトの奥付、ファイル名を指定するとそれがcolophon.htmlとしてコピーされる
colophon: true
texstyle: techbooster-doujin
texdocumentclass: ["jsbook", "b5j,twoside,openany"]
//}

記述できる項目は多いので、Re:VIEW公式のサンプルとWikiを参照してください。

: サンプル
  @<href>{https://github.com/kmuto/review/blob/master/doc/sample.yml}
: Wiki
  @<href>{https://github.com/kmuto/review/wiki/config.yml}

== ページサイズを変更する

PDF形式で出力するページサイズを指定するには、config.ymlの@<code>{textdocumentclass:}項目の２番目の値を設定します（@<list>{change_pagesize}）。

この設定は、LaTeXにおけるドキュメントクラスのオプションに該当します。複数のオプションがある場合は、カンマで区切って列挙します。
技術書であればb5jサイズが標準的です。

//list[change_pagesize][config.ymlにてページサイズをb5jに指定]{
texdocumentclass: ["jsbook", "b5j"]
//}

//table[papersize][設定できるページサイズ]{
値	用紙サイズ
-----------
a4paper	A4
b5paper	B5
a4j	A4 JIS
b5j	B5 JIS
//}

@<table>{papersize}は、@<code>{jsbook}ドキュメントクラスに設定できる代表的な用紙サイズです。
指定するドキュメントクラスによっては、設定できる値が異なる場合があるので注意してください。

== 目次に表示する項目をカスタマイズする

目次として抽出する章や節の深さを変更するには、config.ymlの@<code>{toclevel:}項目を設定します（@<list>{toclevel}）。

//list[toclevel][抽出レベルを設定]{
toclevel: 2
//}

抽出レベルを変更すると、値に応じた深さの見出しを出力します（@<img>{toclevel2}および@<img>{toclevel3}）。

//image[toclevel2][toclevel:2を指定した場合の目次][scale=0.35]{
//}

//image[toclevel3][toclevel:3を指定した場合の目次][scale=0.35]{
//}

== 紙面レイアウトを変更する

印刷所へ入稿する原稿を制作していると、Re:VIEWが標準で用意している構成そのものを変更する必要に迫られる時があります。
Re:VIEWではPDFを出力するためにLaTeXを利用しています。そのため、レイアウトの変更にはLaTeXの知識が必要です。

具体的には.ymlや.cssを配置しているディレクトリの下に@<code>{layouts/layout.tex.erb}を置くことで
Re:VIEWが出力するLaTeXソースファイルの構成を変更できます。

Re:VIEWは@<href>{https://github.com/kmuto/review}の@<code>{review/lib/review/review.tex.erb}を、
LaTeXのソースファイルのテンプレートとして読み込みますが、@<code>{layouts/layout.tex.erb}がある場合、そちらを優先して適用します。

//footnote[review_tex_erb][2013年11月時点。最新の情報についてはGitHubのRe:VIEWリポジトリを参照してください]

カスタマイズに当たっては、@<code>{review/lib/review/review.tex.erb}を@<code>{layouts/layout.tex.erb}にコピーして変更するとよいでしょう。

//image[how_to_convert_re_to_pdf2][layout.tex.erbの取り扱い][scale=0.35]{
//}
