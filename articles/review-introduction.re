={review-introduction} Re:VIEWの書き方

TODO mstssk

=={review_markup} 記法の紹介

Re:VIEW記法は、執筆した文章をマークアップするための記法であり、Re:VIEWの出力結果の最終的な仕上がりを左右するもっとも重要な要素のひとつです。

たとえば、技術書では、本文にクラスやメソッドの名前を記述する場合、その部分を@<i>{イタリック}にしたり@<tt>{等幅フォント}にすることで、
視覚的に差別化することは一般的に行われています。

//list[list_sample][適切な番号の割り当て＋キャプションを表示]{
また、画像やプログラムリストを掲載する場合、視覚的な差別化はもとより、本文から十分な余白をとり、かつ適切な場所に配置することも大切です。
//}

さらに、掲載した画像やリストに本文で言及するために、それぞれ一意な番号を割り当てます（@<list>{list_sample}）。

Re:VIEW記法でマークアップすることで、文章の構造や見た目を指定できます。
マークアップの巧拙が表現力の差となり、高い表現力は、読者にとってわかりやすい文章につながります。

本章では、執筆にあたって適切なマークアップを選択できるように、利用頻度の高いRe:VIEW記法について解説します。

また本書には、付録としてRe:VIEW記法のチートシートを収録しています。そちらもあわせて参照してください。

#@# あめ玉: first_review_projectで@<chap>の説明がここにあることを仮定してます。入れるか、入れないようであれば連絡ください。
#@# @<chap> Now available!

=== インライン命令とブロック命令

Re:VIEW記法は、「インライン命令」と「ブロック命令」の２つに分類できます。

==== インライン命令

インライン命令は、@<tt>{＠<命令>{...}}のように、@<kw>{＠,アットマーク}に続けて括弧<>内に命令名を指定します。
続く括弧{}の中が、インライン命令の効果が及ぶ範囲になります。

インライン命令は、文章の装飾やリストや図の参照など表示や内容に影響します。
文中に直接記入することができますが、改行をまたぐことはできません。

==== ブロック命令

ブロック命令は、@<list>{block_directive}のように、スラッシュ２つ（@<tt>{//}）に続けて命令名を指定します。
続く括弧{から、次の@<tt>{//}}までが、ブロック命令の効果が及ぶ範囲になります。

//list[block_directive][ブロック命令]{
 //命令{
 ...
 //}
//}

ブロック命令には、複数のオプションを指定できる場合があります。
オプションは、命令に続けて括弧[]の中に記述します（@<list>{block_directive_with_option}）。

指定可能なオプションの数や省略の可否は、命令によって違います。

//list[block_directive_with_option][ブロック命令]{
 //命令[オプション1][オプション2][オプション3]{
 ...
 //}
//}

ブロック命令は、リストや図など本文とは独立した内容を掲載する際に使います。

ブロック命令を文の途中から開始することはできません。ブロック命令の開始と終了は、必ず行頭に記述する必要があります。
行頭に半角スペースなどが入った場合、Re:VIEWは、その行をブロック命令として扱いません。

=== 見出し

見出しは、=から始めて、キャプションを続けます。

@<code>{=}は、必ず行頭から開始する必要があります。
また、=の後ろには、必ず半角スペースを入れる必要があります。

@<code>{=}の数によって見出しの深さが変わります。
数に応じてそれぞれ章、節、項、段、小段の5段階に対応します（@<list>{captions}）。

//list[captions][キャプションと対応]{
= 章のキャプション

== 節のキャプション

=== 項のキャプション

==== 段のキャプション

===== 小段のキャプション
//}

Re:VIEWは、6段階以上の見出しには対応していませんが、一般的な文書では「項」レベルまであれば十分でしょう。

章、節、項それぞれの見出しで含まれる内容のバランスを保つことで、読みやすい構造になります。

==== 参照

他の見出しを参照することができます。

見出しの参照を使わず、見出しのキャプションや番号を記述した場合、見出しの追加や削除、順番の変更が発生するたびに、
変更のあった見出しに言及しているファイルを漏れなく探し出し、関係する箇所をすべて変更しなくてはなりません。

一方、見出しの参照を使うとと、順番を入れ替えるなどして見出しの番号が変わっても、変更は自動的に反映されます。

見出しの参照は、大きく「章の参照」と「節の参照」の２つに分類できます。

===== 章の参照

#@# mstssk 「={hoge}」の様に任意に付けるidについても記載したい

章を参照する構文です。

@<list>{refer_chap}は、３つとも@<chapref>{writing-book}を参照しています。

//list[refer_chap][章の参照]{
＠<title>{writing-book}

＠<chap>{writing-book}

＠<chapref>{writing-book}
//}

@<tt>{title}は、その章のキャプションになります（@<title>{writing-book}）。

@<tt>{chap}は、その章の見出し番号になります（@<chap>{writing-book}）。

@<tt>{chapref}は、その章の見出し番号とキャプションになります（@<chapref>{writing-book}）。

これらの構文の参照先には、Re:VIEWの章の識別子を指定します。

章の識別子は、Re:VIEWの章のファイル名から拡張子@<tt>{.re}を取り除いた名前です。
たとえば、@<tt>{writing-book.re}の章を参照する場合、@<tt>{writing-book}が識別子になります。

===== 節の参照

章より一段深い階層にある「節」を参照する構文です。

//list[refer_section][見出しの参照]{
＠<hd>{見出し}

＠<hd>{writing-book|Re:VIEWの特色}
//}

同じ章の節を参照する場合、参照先には、節のキャプションだけを記載します。

異なる章の見出しを参照する場合、章の識別子を指定した上で、縦棒@<tt>{|}で区切って節のキャプションを記述します。

章の識別子は、Re:VIEWの章のファイル名から拡張子@<tt>{.re}を取り除いた名前です。
たとえば、@<tt>{writing-book.re}の章を参照する場合、@<tt>{writing-book}が識別子になります。

===== 見出しラベル

節の参照では、見出しのキャプションをそのまま記述するので、キャプションを変更したときに参照を更新する必要があります。

Re:VIEWでは、見出しキャプションとは別に、参照用のラベルを指定できます。

//list[section_label][見出しの参照用ラベル]{
 =={review_markup} Re:VIEW記法
//}

@<list>{section_label}の括弧{}の中が節の識別子になり、@<list>{refer_section_label}のように参照します。

//list[refer_section_label][見出しの参照]{
＠<hd>{review_markup}
//}

通常の節の参照同様、違う章の節を参照することもできます。

=== リード文

ひとまとまりの文章の内容を、簡単に説明する短い文章を「リード文」と言います。

//list[sammple_lead][リード文]{
 //lead{
 本章では、Re:VIEWで執筆をする上でもっとも重要となるRe:VIEW記法について解説します。
 //}
//}

@<list>{sammple_lead}のマークアップは、次のように出力されます。

//lead{
本章では、Re:VIEWで執筆をする上でもっとも重要となるRe:VIEW記法について解説します。
//}

このように、リード文としてマークアップした内容は、本文に比べて左側の余白が大きくなります。

Re:VIEWでは、リード文のマークアップは、文章のどこにでも置くことができます。
しかし、基本的には見出し、特に章見出しの直下に置くことを想定しています。

=== 段落と改行

文章と文章の間に空行を挟むと、それぞれが個別の段落として処理されます。


２つ以上空行を入れても段落分けには影響しません。


また、Re:VIEWでは、
空行を挟まない改行は無視され、出力には影響しません。      １つ以上の半角スペースも、出力には影響しません。

＠<br>{}を使うと、強制的に@<br>{}
改行@<br>{}
できます。

//list[sections][段落を含む文章]{
Re:VIEW記法の段落は、空行を挟んで文章を続けます。


２つ以上空行を入れても段落分けには影響しません。

また、Re:VIEWでは、
空行を挟まない改行は無視され、出力には影響しません。      １つ以上の半角スペースも、出力には影響しません。

＠<br>{}を使うと、強制的に＠<br>{}
改行＠<br>{}
できます。
//}

=== コメント

行が@<tt>{#@#}から始まる場合、その行についてはコメントとして扱われ、最終出力には影響しません。

#@#この行はコメントです。
Re:VIEWは、複数行コメントには対応していません。
複数行をコメントとして扱うには、すべての行に@<tt>{#@#}を含める必要があります。

//list[comments][コメント]{
コメントの内容は、出力に影響しません。

#＠#この行はコメントです。
Re:VIEWは、複数行コメントには対応していません。
複数行をコメントとして扱うには、すべての行に#@#を記述する必要があります。
//}

=== 箇条書き

項目を列挙する際に、箇条書きを利用できます。

Re:VIEWは、「番号なし箇条書き」と「番号つき箇条書き」に対応しています。

==== 番号なし箇条書き

*に続いて項目を続けると箇条書きになります。
番号なし箇条書きは入れ子に対応しており、*の数が階層になります。

*の前後には、半角スペースが必要です。半角スペースがない場合は、Re:VIEWはその行を本文として取り扱います。

//list[num_sample][番号無し箇条書き]{
 * 箇条書き
 ** 2層目
 *** 3層目
 ** 2層目
 * 箇条書き
//}

@<list>{num_sample}のマークアップは、次のように出力されます。

 * 箇条書き
 ** 2層目
 *** 3層目
 ** 2層目
 * 箇条書き

==== 番号あり箇条書き

@<code>{1. }に続いて項目を続けると箇条書きになります。

先頭とピリオドの後に半角スペースが必要です。番号あり箇条書きは、入れ子に対応していません。

//list[num_sample2][番号付き箇条書き]{
 1. 番号つき箇条書き
 2. 番号つき箇条書き
 3. 番号つき箇条書き
//}

@<list>{num_sample2}のマークアップは、次のように出力されます。

 1. 番号つき箇条書き
 2. 番号つき箇条書き
 3. 番号つき箇条書き

また番号部分の連番を誤った場合でも自動的に連番に置き換わります。
//list[num_sample3][番号付き箇条書き]{
 1. 番号つき箇条書き
 2. 番号つき箇条書き
 2. 番号つき箇条書き
//}

@<list>{num_sample3}のマークアップは、次のように出力されます。

 1. 番号つき箇条書き
 2. 番号つき箇条書き
 3. 番号つき箇条書き

このように、番号部分は自動的に連番に置き換わります。
しかし、行の追加や削除の際は、可能な限り番号を書き換えることをお勧めします。組版や校正時のミスを予防できます。

=== リスト

プログラムコードなど、本文とは分けて掲載する内容を「リスト」と言います。
リストの中の改行やスペースはそのまま出力されます。

@<hd>{段落と改行}で述べたとおり、Re:VIEWでは本文中の複数の半角スペースや改行は、本文には影響しません。
しかし、プログラムなどを掲載したい場合、改行やインデントなどはそのまま出力する必要があります。
このような場合にリストは有効です。

Re:VIEWのリストには、連番付きと連番無しの２種類、行番号の有無を含めると計４種類があります。

//table[list_table][リストの区分]{
.	行番号なし	行番号あり
-------------------------
連番付き	list	listnum
連番なし	emlist	emlistnum
//}

連番つきリストにすると、Re:VIEWは、リストごとに一意な番号を割り振ります。

//list[list_sample_with_seq][連番付きリスト]{
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
//}

番号が割り当てられたリストは、@<list>{refer_list_sample_with_seq}のように本文から参照できます。

//list[refer_list_sample_with_seq][リストの参照]{
番号が割り当てられたリストは、＠<list>{list_sample_with_seq}のように本文から参照できます。
//}

一方、連番なしリストは、リストに番号を割り当てません。

//emlist[連番無しリスト]{
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
//}

番号が割り当てられていない場合、本文からは参照できません。

一般的に、ソースコードリストのように本文から参照する場合には、連番付きリスト（list）を推奨します。
参照関係が明らかな場合のみ、連番なしリスト（emlist）を利用するといいでしょう。

==== 連番つきリスト

連番付きのリストです。

キャプションには、ソースコードファイル名や処理内容など、リストの示す内容を簡潔に記述します。
連番付きリストのキャプションは省略できません。

//list[list_sample_with_seq2][連番付きリスト]{
 //list[identifier][連番付きリストのキャプション]{
  ...ソースコード等...
 //}
//}

@<list>{list_sample_with_no_seq2}のマークアップは、次のように出力されます。

//list[identifier_dummy1][連番付きリストのキャプション]{
 ...ソースコード等...
//}

＠<list>{@<tt>{identifier}}で、@<kw>{identifier,識別子}が示すリストを参照できます。
参照は、出力時に「@<list>{list_sample_with_seq2}」のようにリスト番号に置き換わります。

==== 連番なしリスト

連番なしのリストです。

キャプションには、ソースコードファイル名や処理内容など、リストの示す内容を簡潔に記述します。
連番なしリストのキャプションは省略できます。

//list[list_sample_with_no_seq2][連番なしリスト]{
 //emlist[連番なしリストのキャプション（省略可能）]{
  ...ソースコード等...
 //}
//}

@<list>{list_sample_with_no_seq2}のマークアップは、次のように出力されます。

//emlist[連番なしリストのキャプション（省略可能）]{
 ...ソースコード等...
//}

連番無しリストは、本文中からの参照はできません。

==== 連番つきリスト（行番号有り）

連番付きのリストで、かつ、自動的に行番号が表示されます。

キャプションには、ソースコードファイル名や処理内容など、リストの示す内容を簡潔に記述します。
連番付きリストのキャプションは省略できません。

//list[listnum_sample_with_seq2][行番号有り連番付きリスト]{
 //listnum[identifier][行番号有り連番付きリストのキャプション]{
  ...
  ソースコード等
  ...
 //}
//}

@<list>{listnum_sample_with_seq2}のマークアップは、次のように出力されます。

//listnum[identifier_dummy2][行番号有り連番付きリストのキャプション]{
 ...
 ソースコード等
 ...
//}

＠<list>{@<tt>{identifier}}で、@<kw>{identifier,識別子}が示すリストを参照できます。
参照は、出力時に「@<list>{listnum_sample_with_seq2}」のようにリスト番号に置き換わります。

==== 連番なしリスト（行番号有り）

連番なしのリストで、かつ、自動的に行番号が表示されます。

キャプションには、ソースコードファイル名や処理内容など、リストの示す内容を簡潔に記述します。
連番なしリストのキャプションは省略できます。

//list[emlistnum_sample_with_no_seq2][行番号有り連番なしリスト]{
 //emlistnum[行番号有り連番なしリストのキャプション（省略可能）]{
 ...
 ソースコード等
 ...
 //}
//}

@<list>{emlistnum_sample_with_no_seq2}のマークアップは、次のように出力されます。

//emlistnum[行番号有り連番なしリストのキャプション（省略可能）]{
...
ソースコード等
...
//}

連番無しリストは、本文中からの参照はできません。

行番号をつける場合は、通常、本文からの参照・説明を意図していることが多く、また、後述する不具合があるので、利用頻度がきわめて低い構文です。

=== コマンドライン

コマンドラインの入出力などを示す構文です。

//list[cmd_sample][引用]{
 //cmd{
 $ git add .gitignore
 $ git commit -m "first commit"
 $ git push
 Counting objects: 10, done.
 Delta compression using up to 4 threads.
 Compressing objects: 100% (6/6), done.
 Writing objects: 100% (6/6), 25.21 KiB | 0 bytes/s, done.
 Total 6 (delta 4), reused 0 (delta 0)
 To git@github.com:TechBooster/C85-ReVIEW.git
    261af41..9c23bd9  master -> master
 //}
//}

@<list>{cmd_sample}のマークアップは、次のように出力されます。

//cmd{
$ git add .gitignore
$ git commit -m "first commit"
$ git push

Counting objects: 10, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 25.21 KiB | 0 bytes/s, done.
Total 6 (delta 4), reused 0 (delta 0)
To git@github.com:TechBooster/C85-ReVIEW.git
   261af41..9c23bd9  master -> master
//}

Re:VIEWは、コマンドラインの中の改行やスペースをそのまま出力します。

また、コマンドラインは、本文中からの参照はできません。

=== 引用

ウェブサイトや書籍などから引用した文章を示す構文です。

//list[quote_sample][コマンドライン]{
 //quote{
 文章を記述するための軽量マークアップ言語はRe:VIEWの他にもいくつもあります。
 たとえば、Wikipediaなどで使われるWiki記法も軽量マークアップ言語です。
 IT技術者業界では、他にもMarkdown,reStructuredText,Textileといった例があります。
 //}
//}

@<list>{quote_sample}のマークアップは、次のように出力されます。

//quote{
文章を記述するための軽量マークアップ言語はRe:VIEWの他にもいくつもあります。
たとえば、Wikipediaなどで使われるWiki記法も軽量マークアップ言語です。
IT技術者業界では、他にもMarkdown,reStructuredText,Textileといった例があります。
//}

Re:VIEWは、引用の中の改行やスペースをそのまま出力します。

また、引用は、本文中からの参照はできません。

=== リンク

URLをリンクとしてマークアップする構文です。

リンクには、出力したときにURLを表示する場合と、しない場合の２つの方法があります。

@<list>{link_sample_with_url}は、URLを表示する場合です。

//list[link_sample_with_url][URLリンク]{
＠<href>{http://techbooster.org}
//}

@<list>{link_sample_with_url}を出力した結果は、"@<href>{http://techbooster.org}"のようにURLがそのまま表示されます。

また、@<list>{link_sample}は、URLを表示しない場合です。

URLに加えて、コンマで区切ってリンクを設定する文字列を続けます。

//list[link_sample][リンク（URL無し）]{
＠<href>{http://techbooster.org,TechBooster}
//}

@<list>{link_sample}を出力した結果は、"@<href>{http://techbooster.org,TechBooster}"のようにURLが表示されず、文字列にリンクが設定された状態になります。

当然のことながら、どちらの場合でも紙に印刷するとリンクは使えなくなりますが、URLを表示する方法では印刷後でもURLそのものは分かるので、
最終的に印刷する場合は、URLを表示する方法が適しています。

=== 脚注

本文に別の情報を付記する構文です。「注釈」とも呼ばれます。

@<list>{footnote_sample}は、脚注を記述した例です。

//list[footnote_sample][コマンドライン]{
 //footnote[identifier][脚注の内容は、ページで本文とは別の「脚注の領域」に表示されます]
//}

//footnote[about_footnote][脚注の内容は、ページで本文とは別の「脚注の領域」に表示されます]
#@# //footnote[not_reffered_footnote][参照されない脚注は表示されません]

脚注は、記述した場所に関係なく「脚注の領域」に表示されます。

脚注を有効にするには、本文で参照している必要があります。本文で参照されていない脚注は出力されません。

@<list>{footnote_refer_sample}では、記述した脚注を参照しています。

//list[footnote_refer_sample][脚注への参照]{
本文から参照すると、脚注番号が付記されます＠<fn>{identifier}。
//}

＠<fn>{@<tt>{identifier}}で、@<kw>{identifier,識別子}が示す脚注を参照できます。

本文から参照すると、脚注番号が付記されます@<fn>{about_footnote}。

=== 図

写真や挿絵などを「図」として、本文中に差し込むことができます。

差し込む写真や図面などは別ファイルで保存しておき、本文中に参照を記述します。

==== 画像ファイル

本文に差し込む画像ファイルは、CHAPSがあるディレクトリに@<code>{images}ディレクトリを作成します。
それぞれの画像ファイルは、その画像を差し込む章の名前のディレクトリの下に配置します。

たとえば、@<tt>{markup.re}の章に表示する画像ファイル@<tt>{enlightened.png}のばあい、@<tt>{images/markup/enlightened.png}となります。
このことから解るとおり、Re:VIEWでは、異なる章の画像ファイルを直接参照することはできません。
画像ファイルは、章ごとに配置する必要があります。

画像ファイルとして利用できるフォーマットは、Re:VIEWで出力する形式に依存しますが、PNG、JPEG、@<kw>{SVG,Scalable Vector Graphics}など、基本的なフォーマットには対応しています。

//image[enlightened][enlightened.png]{
//}

==== 連番付きの図

キャプションには、ファイル名や処理内容など、内容を簡潔に記述します。
キャプションは省略できません。

//list[image_sample_with_seq][連番付きの図]{
 //image[enlightened][連番付きの図]{
 ...代替テキスト等...
 //}
//}

@<list>{image_sample_with_seq}のマークアップは、次のように出力されます。

//image[enlightened_dup1][連番付きの図]{
//}

＠<img>{@<tt>{identifier}}で、本文から@<kw>{identifier,識別子}が示す図を参照できます。

参照は、出力時に「@<img>{enlightened_dup1}」のようにリスト番号に置き換わります。

@<tt>{代替テキスト}は、出力時には無視されます。
基本的にはアスキーアートや文章で画像の説明をして、執筆時にどんな画像を意図しているのか確認するために使いますが、何も書かなくても問題ありません。

==== 連番なしの図

キャプションには、ファイル名や処理内容など、内容を簡潔に記述します。
キャプションは省略できません。

//list[image_sample_with_no_seq][連番なしの図]{
 //indepimage[enlightened][連番なしの図]
//}

@<list>{image_sample_with_no_seq}のマークアップは、次のように出力されます。

//indepimage[enlightened][連番なしの図]

連番なしの図は、本文中からの参照はできません。また、@<tt>{代替テキスト}は指定できません。

==== 図のサイズを指定する

スケールオプションで図の表示倍率を指定することができます。

スケールオプションは、@<code>{image}、@<code>{indepimage}に括弧[]を追加して、@<tt>{scale=}に続いて表示倍率を指定します。

表示倍率は、@<tt>{1.0}を等倍、@<tt>{0.0}を下限として指定できます。

//list[scaled_image_sample_with_seq][連番付きの図]{
 //image[enlightened][表示倍率50%]@<b>{[scale=0.5]}{
 ...代替テキスト等...
 //}
//}

//image[enlightened_dup2][表示倍率50%][scale=0.5]{
...代替テキスト等...
//}

//list[scaled_image_sample_with_no_seq][連番なしの図]{
 //indepimage[enlightened][表示倍率25%]@<b>{[scale=0.25]}
//}

//indepimage[enlightened][表示倍率25%][scale=0.25]

スケールオプションを省略した場合、Re:VIEWは、自動で適切なサイズを選択します。
スケールを指定した結果、図が紙面からはみ出る場合もあるので、注意してください。

=== 表

罫線で区切られた表をマークアップする構文です。

Re:VIEWでは、行は改行、セルとセルの間にはタブで区切ります。

空白のセルは、ピリオド（@<tt>{.}）を入力します。

セルにピリオドを表示したい、またはセルの内容をピリオドから始めたい場合、ピリオドを２つ続けて（@<tt>{..}）入力します。

また、@<tt>{-------------}で区切ることで、ヘッダの行を明確に指定できます。

//list[table_sample][表]{
 //table[identifier][表のキャプション]{
 .	A	B	C	D	E
 ------------------
 1	2012	500	800	1.0	..15
 2	2013	600	.	1.1	..13
 3	2014	900	1200	1.4	..18
 //}
//}

@<list>{table_sample}のマークアップは、@<table>{table_sample}のように出力されます。

//table[table_sample][表のキャプション]{
.	A	B	C	D	E
------------------
1	2012	500	800	1.0	..15
2	2013	600	.	1.1	..13
3	2014	900	1200	1.4	..18
//}

＠<table>{@<tt>{identifier}}で、@<kw>{identifier,識別子}が示す表を参照できます。
参照は、出力時に「@<table>{table_sample}」のように表番号に置き換わります。

=== 文字の装飾

Re:VIEW記法では、文字を装飾することができます。

文字の装飾は、基本的には、適用したい範囲を@<tt>{＠<修飾子>{...}}で指定するだけです。

また、文字の装飾は、本文だけでなく、リストや脚注、表などの中でも有効です。

比較的、利用頻度の高い文字の装飾について@<table>{character_decorations}にまとめています。

//table[character_decorations][文字の装飾]{
修飾子	説明	例
------------------
＠<b>{文字列}	太字（ボールド）フォント	@<b>{abcdefg あいうえお}
＠<i>{文字列}	イタリックフォント	@<i>{abcdefg あいうえお}
＠<tt>{文字列}	等幅フォント	@<tt>{abcdefg あいうえお}
＠<ttb>{文字列}	太字（ボールド）＆等幅フォント	@<ttb>{abcdefg あいうえお}
＠<tti>{文字列}	イタリック＆等幅フォント	@<tti>{abcdefg あいうえお}
＠<em>{文字列}	強調	@<em>{abcdefg あいうえお}
＠<strong>{文字列}	強調	@<strong>{abcdefg あいうえお}
＠<ami>{文字列}	網掛け	@<ami>{abcdefg あいうえお}
＠<kw>{キーワード,解説}	キーワードと解説	@<kw>{GNU,GNU is Not Unix}
//}

== 設定ファイルの解説

TODO mstssk

=== catalog.yml

#@# https://github.com/kmuto/review/wiki/catalog.yml
#@# https://github.com/kmuto/review/blob/master/doc/catalog.ja.md

catalog.ymlは章立ての設定ファイルです。
各章の.reファイルを列記し、PDFをビルドをした際の章の順序を定義します。

@<list>{catalog_yml_sample}は、TechBoosterがコミックマーケット88で頒布したJavaScriptoonの実際のcatalog.ymlです（@<fn>{url_javascriptoon}）。

//list[catalog_yml_sample][JavaScriptoonのcatalog.yml]{
PREDEF:
  - preface.re

CHAPS:
  - laco0416.re
  - mstssk.re
  - gam0022.re
  - nyamadan.re
  - laco0416_stream.re
  - amedama_fido.re
  - vvakame.re

APPENDIX:

POSTDEF:
  - contributors.re
//}

catalog.ymlの各項目の内容は次のとおりです。

: PREDEF
  前書きなど目次の前に記載するものを指定します。
: CHAPS
  本文の各章を指定します。TechBoosterでは各著者が各章を担当するので、著者名をそのままファイル名に使っています。
: APPENDIX
  付録となる章を指定します。
: POSTDEF
  後書き。TechBoosterでは著者紹介を載せています。

くわえて、CHAPSはネストすることで@<b>{部}を構成することができます。
部を構成するには、@<list>{catalog_yml_nested_chaps}のように、部のタイトル名や.reファイル名の下に章のファイルを記述します。
YAMLに馴染みがないと忘れがちですが、Collection（@<fn>{url_yaml_collection}）にする必要があるのでコロン記号（：）を付け忘れないようにしましょう。

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

//footnote[url_javascriptoon][@<href>{https://techbooster.github.io/c88/#scriptoon}]
//footnote[url_yaml_collection][@<href>{http://www.yaml.org/spec/1.2/spec.html#id2759963}]

====[column] 章立ての古い方法
Re:VIEWのバージョン1.2以前ではcatalog.ymlが無く、PREDEFやCHAPSを個別のファイルに記載していました。
現在でも古い方法はサポートされていますが、基本的にはcatalog.ymlを使ったほうがいいでしょう。
また、APPENDIXはバージョン1.3で追加されたので、古い方法ではサポートされていません。
====[/column]

=== config.yml

#@# https://github.com/kmuto/review/wiki/config.yml

config.ymlは本を生成する時のメタデータ記述ファイルです。
書名や、奥付の内容、どの深さまで目次に含めるかなどを設定できます。
記述できる項目は多いので、Re:VIEW公式のサンプルとWikiを参照してください。

: サンプル
  @<href>{https://github.com/kmuto/review/blob/master/doc/sample.yml}
: Wiki
  @<href>{https://github.com/kmuto/review/wiki/config.yml}

=== スタイル

== コンパイルの仕方

TODO mstssk
TODO mstssk review-preproc などサブコマンドについても少々扱ってほしい
TODO mstssk *-peg についてコラムがあると嬉しいなー
