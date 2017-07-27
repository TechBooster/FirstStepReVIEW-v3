={build} 書籍をビルドする

本章ではRe:VIEWファイルをコンパイルする方法を解説します。
PDFを出力する@<code>{review-pdfmaker}、EPUBを出力する@<code>{review-epubmaker}、Webページを出力する@<code>{review-webmaker}、
フォーマットを変換する@<code>{review-compile}を順番に紹介します。

入稿に利用する形式は@<code>{review-pdfmaker}コマンドでのPDF形式ですが、Re:VIEWは、Markdown、プレーンテキスト、HTMLやEPUBなど多様なフォーマットに対応しています。

== review-pdfmaker

@<code>{review-pdfmaker}はそのプロジェクトのPDFを生成します。
引数としてYAMLファイル（@<tt>{config.yml}）をひとつ指定します。

//cmd{
> review-pdfmaker config.yml
(出力省略)
//}

YAMLファイルには本のタイトルや筆者名といった本のメタデータとなる設定を記述しておきます。
その設定のひとつ@<code>{bookname}が出力ファイル名に対応しています。

@<code>{bookname}が「book」となっている場合、生成した@<tt>{book.pdf}を自身のディレクトリに保存します。
#@# NOTE vv: この辺変わってる 基本はtmpdirに出力される --debug 有りでbook-pdfディレクトリに出力するが、その場合も古いディレクトリは自動的に削除されてから処理が実行される
#@# https://github.com/kmuto/review/blob/331aa87595b5188fc765e04a81ae8205dac41785/lib/review/pdfmaker.rb#L63-L74
#@# 対応済み

@<code>{review-pdfmaker}は内部で後述のコマンド@<code>{review-compile --target=latex}を実行します。
そのあとに@<code>{platex}や@<code>{dvipdfmx}のようなTeX形式のファイルからPDFへ変換する外部コマンドを実行します。
Re:VIEW外部のコマンドを実行している際には外部のログがそのまま標準出力や標準エラー出力に反映されるため、驚くかもしれません。

=== 制作時の注意点

@<code>{review-pdfmaker}をはじめて使うときは作法がわからず戸惑うかもしれません。
もっとも単純な事例では、catalog.ymlの@<code>{CHAPS}で章の指定を忘れることです。
構文エラーが発生すると標準出力に発生時点のエラーログが残ります。これを手がかりに問題の箇所を探すことになります。

リストに掲載したソースコードが長すぎて紙面をはみ出している場合、箇条書きのつもりで書いた「@<code>{*}」が半角スペースを忘れていて直接本文に表示されている場合など
見た目の問題についてはビルドエラーとはなりません。

執筆後半となると、見栄えの調整のために頻繁に@<code>{review-pdfmaker}を実行するので注意すべきポイントとして覚えておくとよいでしょう。
意図したレイアウトでPDFが出力されているかは作成者によるケアが必要です。

== review-epubmaker

@<code>{review-pdfmaker}同様、@<code>{review-epubmaker}はプロジェクトのメタデータとなるYAMLファイルを引数としてEPUBファイルを生成します。
EPUBファイルの実態はHTMLファイルやCSSファイルをZIPでアーカイブ化したものです。

Re:VIEWはEPUBの生成処理で、システムにインストールされているZIPコマンドを使用します。
事前にZIPコマンドをインストールしておいてください。

//cmd{
> review-epubmaker config.yml
(出力省略)
> file book.epub
book.epub: EPUB ebook data
（電子書籍リーダに読み込ませることで内容を確認出来る）
//}

YAMLファイル内の@<code>{bookname}を元にして出力されるファイル名を決定します。

コマンド内部で後述の@<code>{review-compile}を利用しており、HTML生成のオプションには@<tt>{config.yml}に項目がないものもあります。
そういったオプションを使用するには@<code>{review-compile}コマンドのオプションを任意に記述できる@<code>{params}という項目を使います。
@<list>{config_yml_chapterlink}は@<code>{--chapterlink}オプションを設定する例です。

//list[config_yml_chapterlink][--chapterlinkオプションをconfig.ymlで指定する]{
bookname: C89-FirstStepReVIEW-v2
stylesheet: ["style.css"]
epubversion: 3
〜中略〜
params: --chapterlink
//}

== review-webmaker

@<code>{review-webmaker}はプロジェクトのメタデータとなるYAMLファイルを引数としてWebサイト用ファイルを生成します。
HTMLファイルやCSSファイル、画像を@<tt>{webroot}ディレクトリに出力します。

//cmd{
> review-webmaker config.yml
(出力省略)
> file webroot
webroot: directory
//}

読み込むCSSファイルなどは参照するYAMLファイル内の@<code>{webmaker}パラメータを元にして設定しています（@<img>{webroot}）。

//image[webroot][review-webmakerの出力例][scale=0.75]{
//}

== review-compile

@<code>{review-compile}はRe:VIEWファイル１つを@<code>{--target}オプションで指定するフォーマットに変換します。

もっとも簡単な例として、HTMLを出力する例を@<list>{review-compile-example-html-1}に示します。

//list[review-compile-example-html-1][review-compileでHTMLを出力する例]{
> review-compile --target=html preface.re
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml"
  xmlns:epub="http://www.idpf.org/2007/ops"
  xmlns:ops="http://www.idpf.org/2007/ops"
  xml:lang="ja">
<head>
  <meta charset="UTF-8" />
  <link rel="stylesheet" type="text/css" href="style.css" />
  <meta name="generator" content="Re:VIEW" />
  <title>はじめに</title>
</head>
<body>
<h1><a id="h"></a>はじめに</h1>
<p>技術書をかこう！〜はじめてのRe:VIEW〜を手に取っていただき、ありがとうございます。本書は色々な種類・性質の技術書がもっと世の中に溢れてほしい、という気持ちから生まれました。本書を支えるRe:VIEWというツールの解説に始まり、印刷を発注し紙の本として体裁を整えるところまでフォローします。つまり、この本は技術書をこの世に誕生させるためのスキルがひととおり身につくガイドブックなのです。</p>
<p>タイトルにもあるRe:VIEWは書籍制作のためのツールセットです。すこしの文法をおぼえるだけで技術書がつくれる優れものです。</p>
... (以下省略)
//}

HTML出力以外にも
プレーンテキスト形式にする@<code>{--target=text}、PDFを出力するために必要なTeX形式のファイルを出力する@<code>{--target=latex}、
軽量マークアップ言語であるMarkdown形式を出力する@<code>{--target=markdown}などがあります。

読者の環境で@<code>{--target}で指定できるフォーマットを調べるには、
Re:VIEW本体のインストール先にある@<code>{lib/review/???builder.rb}というファイル名のファイルを確認するのが早道です。

//cmd{
> ls lib/review/*builder.rb
lib/review/builder.rb      lib/review/ewbbuilder.rb  lib/review/idgxmlbuilder.rb
lib/review/latexbuilder.rb lib/review/textbuilder.rb lib/review/epubbuilder.rb
lib/review/htmlbuilder.rb  lib/review/inaobuilder.rb lib/review/markdownbuilder.rb
lib/review/topbuilder.rb
//}

対応する出力形式の多くはRe:VIEW開発者らが仕事上利用するために用意されました。
執筆時には@<code>{reveiew-webmaker}などを指定する機会が多いでしょうが、こんな変換も可能なんだな、と知っておくと再利用で便利かもしれません。
#@# REVIEW vv: しょうみ、僕は執筆時pdfにしか変換しなくなりましたね… どう？これ以降も僕のやり方とは結構違っているかもしんない。
#@# review mhidaka Atomでlanguage-reviewつかってプレビューみてる

@<code>{--check}を指定すると結果は出力せず、そのフォーマットで入力したファイルが正しく変換できるかを確認します。
たとえば、@<code>{footnote}と@<code>{fn}で対応がとれていなければ、その旨が表示されます。エラーを避けるために便利なヒントです。

//cmd{
> review-compile --check --target=html build.re
build.re:11: error: ReVIEW::KeyError
//}

出力されたhtmlの見栄えを調整するには
@<code>{--yaml=(ファイル名)}でRe:VIEWプロジェクトの設定（@<tt>{config.yml}など）を読み込ませるととよいでしょう。設定ファイル指定のスタイルを変更できます。
#@# REVIEW vv: これなんだっけ config.ymlのこと？

@<code>{--all}を指定すると、指定したファイルだけではなく@<tt>{catalog.yml}に記載されている　すべてのファイルを一気にコンパイルすることもできます。

@<code>{＠<chapref>{chapter\}}や@<code>{＠<hd>{head\}}などの章・見出しの参照をリンクにする@<code>{--chapterlink}というオプションもあります。

なお、@<code>{--help}を指定すると、ファイルを読み込んで変換する代わりに対応するオプションの一覧が表示されます。
本章で説明されていないオプションも多々あるので、必要に応じて参照してください。

=== @<code>{review-compile}の性質

@<code>{review-compile}は主に単一のファイルに対して操作を行います。いわば内部コマンドに近い挙動です。
@<code>{review-pdfmaker}や@<code>{review-epubmaker}などはRe:VIEWプロジェクト全体が対象です。これらコマンドの目的は最終出力なため、用途も異なります。

現時点では@<code>{review-compile}からは直接PDFとEPUB形式のファイルを生成することはできません@<fn>{target_epub_is_not_for_epub}。
仮に執筆途中の一部のRe:VIEWファイルのみ、PDFフォーマットで確認したい場合には自分自身でTeX形式から生成する、
あるいは逆に全体を@<code>{review-pdfmaker}で生成したあと、該当する章をpdktk@<fn>{pdftk}等のコマンドで切り出してください。

//footnote[target_epub_is_not_for_epub][@<code>{--target=epub}は圧縮してEPUB形式とする前のただのHTMLを出力します]
//footnote[pdftk][@<href>{https://www.pdflabs.com/tools/pdftk-the-pdf-toolkit/}]
