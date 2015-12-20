= コンパイルの仕方

本章ではRe:VIEWファイルをコンパイルする方法を解説します。
フォーマットを変換する@<code>{review-compile}、PDFを出力する@<code>{review-pdfmaker}、EPUBを出力する@<code>{review-epubmaker}を順番に紹介します。

入稿に利用する形式は@<code>{review-pdfmaker}コマンドでのPDF形式ですが、Re:VIEWは、プレーンテキスト、HTMLやEPUBなど多様なフォーマットに対応しています。

== review-compile

@<code>{review-compile}Re:VIEWファイル１つを@<code>{--target}オプションで指定するフォーマットに変換します。

最も簡単な例として、HTMLを出力する例を@<list>{review-compile-example-html-1}に示します。

//list[review-compile-example-html-1][review-compileでHTMLを出力する例]{
> review-compile --target=html preface.re
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN"
  "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"
  xmlns:ops="http://www.idpf.org/2007/ops" xml:lang="ja">
<head>
  <meta http-equiv="Content-Type" content="text/html;charset=UTF-8"/>
  <meta http-equiv="Content-Style-Type" content="text/css"/>
  <meta name="generator" content="Re:VIEW"/>
  <title>はじめに</title>
</head>
<body>
<h1><a id="h"></a>はじめに</h1>
<p>はじめてのRe:VEIW 第2版を手に取っていただき、ありがとうございます。本書は色々な種類・性質の技術書がもっと世の中に溢れてほしい、という気持ちから生まれました。最新のRe:VIEWにあわせたアップデートはもちろん、技術書を書くことにフォーカスをあてたガイドブックです。</p>
<p>タイトルにもあるRe:VIEWは書籍制作のためのツールセットです。すこしの文法をおぼえるだけで技術書がつくれる優れものです。</p>
... (以下省略)
//}

#@# REVIEW vvakame amedama系の奴は怒られへんのやろか… 平気？
#@# REVIEW mstssk ↑今回のpreface.reに差し替え。出力もちょっぴり変わってる。

HTML向け出力は、執筆時に「大まかにどのような出力になるのか」を確認するために使います。
その他にもプレーンテキスト形式にする@<code>{--target=text}、PDFを出力するために必要なTeX形式のファイルを出力する@<code>{--target=latex}、軽量マークアップ言語であるMarkdown形式を出力する@<code>{--target=markdown}などがあります。

//footnote[target_epub_is_not_for_epub][@<code>{--target=epub}は圧縮してEPUB形式とする前のただのHTMLを出力します。]

読者の環境で@<code>{--target}で指定できるフォーマットを調べるには、ReVIEW本体のインストール先にある@<code>{lib/review/???builder.rb}というファイル名のファイルを確認するのが早道です。

//cmd{
> ls lib/review/*builder.rb
lib/review/builder.rb        lib/review/ewbbuilder.rb    lib/review/idgxmlbuilder.rb
lib/review/latexbuilder.rb   lib/review/textbuilder.rb   lib/review/epubbuilder.rb
lib/review/htmlbuilder.rb    lib/review/inaobuilder.rb   lib/review/markdownbuilder.rb
lib/review/topbuilder.rb
//}

対応する出力形式の多くはReVIEW開発者らが仕事上利用するために用意されました。執筆時には@<code>{--target=html}を指定する機会が多いでしょう。

@<code>{--check}を指定すると結果は出力せず、そのフォーマットで入力したファイルが正しく変換できるかを確認します。
たとえば、@<code>{footnote}と@<code>{fn}で対応がとれていなければ、その旨が表示されます。
これもまた執筆中にエラーを前もって避けるために便利です@<fn>{for_pdf}。

//cmd{
> review-compile --check --target=html build.re
build.re:11: error: ReVIEW::KeyError
//}

//footnote[for_pdf][@<code>{review-pdfmaker}にはこの機能がない一方、前述した通り@<code>{review-compile}では直接はPDFを出力しません。対策として@<code>{review-compile --check --target=latex}とするとPDFで問題が起こる前に修正できます]

出力されたhtmlを、執筆時のデバッグ用途としてではなく見栄えの良い公開用ファイルにすることもできます。
@<code>{--yaml=(ファイル名)}でReVIEWプロジェクトの設定を読みこませることでスタイルを変更するとよいでしょう。

@<code>{--all}を指定すると、指定したファイルだけではなく、catalog.ymlに記載されている　すべてのファイルを一気にコンパイルすることもできます。

@<code>{＠<chapref>{chapter\}}や@<code>{＠<hd>{head\}}などの章・見出しの参照をリンクにする@<code>{--chapterlink}というオプションもあります。

なお、@<code>{--help}を指定すると、ファイルを読み込んで変換する代わりに対応するオプションの一覧が表示されます。
本章で説明されていないオプションも多々あるので、必要に応じて参照してください。

=== 注意: @<code>{review-compile}ではそのままPDFとEPUBは生成できない

現時点では@<code>{review-compile}からは直接PDFとEPUB形式のファイルを生成することはできません@<fn>{target_epub_is_not_for_epub}。
後述する@<code>{review-pdfmaker}と@<code>{review-epubmaker}をそれぞれ利用してください。

@<code>{review-compile}は主に単一のファイルに対して操作を行う一方、@<code>{review-pdfmaker}と@<code>{review-epubmaker}はReVIEWプロジェクト全体を対象とするため、用途も異なります。
仮に執筆途中のReVIEWファイルのみ、PDFによるフォーマットを確認したい場合、自身でTeX形式から生成する、あるいは逆に全体を@<code>{review-pdfmaker}で生成したあと、該当する章を@<code>{pdktk}等のコマンドで切り出してください。

== review-pdfmaker

@<code>{review-pdfmaker}はそのプロジェクトのPDFを生成します。
引数としてYAMLファイル（@<code>{config.yml}）をひとつ指定します。

//cmd{
> review-pdfmaker config.yml
(出力省略)
//}

YAMLファイルには本のタイトルや筆者名といった本のメタデータとなる設定を記述しておきます。
その設定のひとつ「@<code>{bookname}」が出力されるPDFに対応しています。

@<code>{bookname}が「book」となっている場合、ReVIEWは「@<code>{book-pdf/}」ディレクトリに、途中過程で生成されるファイルを保存した上で、最終的に「book.pdf」を自身のディレクトリに保存します。
仮にこれらのファイル・ディレクトリがすでに存在している場合、ReVIEWはコマンドの実行を中止します。

//list[review-pdfmaker-example-2][すでにPDFを一度作成したあとに再度review-pdfmakerしたときの実行例]{
> review-pdfmaker config.yml
/opt/review/bin/review-pdfmaker:57:in `mkdir':
        File exists - ./book-pdf (Errno::EEXIST)
        from /opt/review/bin/review-pdfmaker:57:in `main'
        from /opt/review/bin/review-pdfmaker:219:in `<main>'
//}

再度コンパイルする際には、まず手動でPDF（book.pdf）と中間ファイルを収めるディレクトリ（book-pdf/）を削除してから、再度@<code>{review-pdfmaker}を実行します。

@<code>{review-pdfmaker}は内部で@<code>{review-compile --target=latex}を行ったあとに@<code>{platex}や@<code>{dvipdfmx}のようなTeX形式のファイルからPDFへ変換するReVIEW外部のコマンドを実行します。
ReVIEWの外部のコマンドを実行している際には外部のログがそのまま標準出力や標準エラー出力に反映されるため、面食らうかもしれません。

=== rakeで自動化

コンパイル前にbook.pdf等を手動で削除する作業は少々面倒です。
そこで、@<code>{rake}コマンドで自動化してしまいましょう。
@<code>{rake}コマンドはRubyGemsから簡単にインストールできます。

//cmd{
gem install rake
//}

@<code>{rake}コマンドに行わせるタスクは@<code>{Rakefile}というファイルに記述します。
@<hd>{setup|install_review}の解説のとおりに@<code>{review-init}コマンドを使って環境を構築していれば、
すでに@<code>{Rakefile}というファイルが存在し、各種タスクが記述されています。

@<code>{Rakefile}が無ければ作りましょう。
@<list>{rakefile-example-1}はpdfのビルドを行う@<code>{Rakefile}の簡単なサンプルです。

//list[rakefile-example-1][Rakefileにbook.pdfとbook-pdfの削除を行わせてしまう一例]{
task :default => :pdf

desc 'generate PDF file'
task :pdf => "book.pdf"

SRC = FileList['*.re'] +  ["config.yml"]
file "book.pdf" => SRC do
  sh "rm -f book.pdf"
  sh "rm -rf book book-pdf"
  sh "review-pdfmaker config.yml"
end
//}

このように記述しておくと、@<code>{rake}コマンドは関連するReVEWファイルや@<code>{config.yml}に変更があった際に限って削除と@<code>{review-pdfmaker}の実行を行います。
#@# REVIEW vvakame 本書でgruntによるタスクの記述を行ってるのでそのあたりにも言及してほしい感じが…
#@# REVIEW mstssk 他章のreview-initの解説ありきだったので書き直しました。↓でタスクランナーの節に参照も追加。

作業を自動化するツールは@<code>{Rakefile}だけではありません。
TechBoosterでは@<code>{grunt}を使って作業を自動化しています。
@<code>{grunt}による自動化は@<hd>{tips|config_task_runner}で解説しています。

=== 執筆時の注意点

@<code>{review-pdfmaker}は、その書籍に含まれるReVIEWファイルに問題があっても、一見正常にPDFを出力してしまいます。
この場合、コマンド自身は「成功」と報告するのですが、該当する章のデータが勝手に抜け落ちている、という事態につながります。

最も単純な事例は、catalog.ymlの@<code>{CHAPS}での指定を忘れることです。
また、一部の構文エラーについても、そのファイルがなかったこととして、PDFが生成されてしまいます。

これは、複数のReVIEWファイルを用いて原稿執筆している際に若干厄介な問題です。
特に執筆後半では、見栄えの調整のために@<code>{review-compile}よりも頻繁に@<code>{review-pdfmaker}等を実行することがあるのですが、@<code>{review-compile}エラーで中止する代わりに、コマンドはエラーが発生した章を無視してPDFを生成します。

対策として、執筆時には@<code>{review-compile --target=latex --check}を実行して執筆中の原稿単体で発生している問題を排除してから@<code>{review-pdfmaker}を実行することをおすすめします。

章がまるまる抜け落ちることを利用してページ数が減っていないか確認することもできます。
参考まで、Linuxの@<code>{pdftk}コマンドでページ数を見る例を示します。

//cmd{
> pdftk book.pdf dump_data_utf8 | grep NumberOfPages
NumberOfPages: 103
//}

== review-epubmaker

@<code>{review-pdfmaker}同様、@<code>{review-epubmaker}はプロジェクトのメタデータとなるYAMLファイルを引数としてEPUBファイルを生成します。
EPUBファイルの実態はHTMLファイルやCSSファイルをZIP圧縮でアーカイブ化したものです。

Re:VIEWはEPUBの生成処理で、システムにインストールされているZIPコマンドを使用します。
事前にZIPコマンドをインストールしておいてください。

//list[review-epubmaker-example-1][review-epubmakerの例]{
> review-epubmaker config.yml
(出力省略)
> file book.epub
book.epub: EPUB ebook data
（電子書籍リーダに読み込ませることで内容を確認出来る）
//}

@<code>{review-pdfmaker}同様、参照するYAMLファイル内の@<code>{bookname}を元にして出力されるファイル名を決定します。

HTML生成のオプションにはconfig.ymlに項目がないものもあります。
そういったオプションを使用するには@<code>{review-compile}コマンドのオプションを任意に記述できる@<code>{params}という項目を使います。
@<list>{config_yml_chapterlink}は@<code>{--chapterlink}オプションを設定する例です。

//list[config_yml_chapterlink][--chapterlinkオプションをconfig.ymlで指定する]{
bookname: C89-FirstStepReVIEW-v2
stylesheet: ["style.css"]
epubversion: 3
〜中略〜
params: --chapterlink
//}
