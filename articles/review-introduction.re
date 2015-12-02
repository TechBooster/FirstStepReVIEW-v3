={review-introduction} Re:VIEWの書き方

//lead{
本章ではRe:VIEWの記法を紹介します。本章では執筆にあたって適切なマークアップを選択できるように、利用頻度の高いRe:VIEW記法について解説します。
//}

=={review_markup} 記法の紹介

Re:VIEW記法は、執筆した文章をマークアップするための記法です。
たとえば技術書では、本文にクラスやメソッドの名前を記述する場合、その部分を@<i>{イタリック}にしたり@<tt>{等幅フォント}にすることで、
視覚的に差別化することは一般的に行われています。

さらに掲載した画像やリストに本文で言及するために、それぞれ一意な番号を割り当てます（@<list>{list_sample}）。

//list[list_sample][適切な番号の割り当て＋キャプションを表示]{
また、画像やプログラムリストを掲載する場合、視覚的な差別化はもとより、本文から十分な余白をとり、かつ適切な場所に配置することも大切です。
//}

Re:VIEW記法でマークアップすることで文章の構造や見た目を指定できます。
マークアップの巧拙が表現力の差となり、高い表現力は、読者にとってわかりやすい文章につながります。

=== インライン命令とブロック命令

Re:VIEW記法は、「インライン命令」と「ブロック命令」の２つに分類できます。

==== インライン命令

インライン命令は@<tt>{＠<命令>{...}}のように、@<kw>{＠,アットマーク}に続けて括弧<>内に命令名を指定します。
続く括弧{}の中が、インライン命令の効果が及ぶ範囲になります。

インライン命令は、文章の装飾やリストや図の参照など表示や内容に影響します。
文中に直接記入することができますが、改行をまたぐことはできません。

==== ブロック命令

ブロック命令は@<list>{block_directive}のように、スラッシュ２つ（@<tt>{//}）に続けて命令名を指定します。
続く括弧{から、次の@<tt>{//}}までが、ブロック命令の効果が及ぶ範囲になります。

//list[block_directive][ブロック命令]{
 //命令{
 ...
 //}
//}

ブロック命令には複数のオプションを指定できる場合があります。
オプションは、命令に続けて括弧[]の中に記述します（@<list>{block_directive_with_option}）。

指定可能なオプションの数や省略の可否は、命令によって違います。

//list[block_directive_with_option][ブロック命令]{
 //命令[オプション1][オプション2][オプション3]{
 ...
 //}
//}

ブロック命令はリストや図など本文とは独立した内容を掲載する際に使います。

ブロック命令を文の途中から開始することはできません。ブロック命令の開始と終了は、必ず行頭に記述します。
行頭に半角スペースなどが入った場合、Re:VIEWは、その行をブロック命令として扱いません。

=== 見出し

見出しは、=から始めて、キャプションを続けます。

@<code>{=}は、必ず行頭から開始します。
また、=の後ろには、必ず半角スペースを入れます。

@<code>{=}の数によって見出しの深さが変わります。
数に応じてそれぞれ章、節、項、段、小段の5段階に対応します（@<list>{captions}）。

//list[captions][キャプションと対応]{
= 章のキャプション

== 節のキャプション

=== 項のキャプション

==== 段のキャプション

===== 小段のキャプション
//}

Re:VIEWは６段階以上の見出しには対応していませんが、一般的な文書では「項」レベルまであれば十分でしょう。
章、節、項それぞれの見出しで含まれる内容のバランスを保つことで、読みやすい構造になります。

==== 参照

他の見出しを参照することができます。

見出しの参照を使わず、見出しのキャプションや番号を記述した場合、見出しの追加や削除、順番の変更が発生するたびに、
変更のあった見出しに言及しているファイルを漏れなく探し出し、関係する箇所をすべて変更しなくてはなりません。

一方、見出しの参照を使うとと、順番を入れ替えるなどして見出しの番号が変わっても、変更は自動的に反映されます。

見出しの参照は、大きく「章の参照」と「節の参照」の２つに分類できます。

===== 章の参照

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

章より一段深い階層にある「節」を参照する構文です（@<list>{refer_section}）。

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

通常の節の参照同様、違う章の節を参照することができる優れものです。

=== リード文

ひとまとまりの文章の内容を、簡単に説明する短い文章を「リード文」と言います。

//list[sammple_lead][リード文]{
 //lead{
 本章ではRe:VIEWで執筆をする上でもっとも重要となるRe:VIEW記法について解説します。
 //}
//}

@<list>{sammple_lead}のマークアップは、次のように出力されます。

//lead{
本章ではRe:VIEWで執筆をする上でもっとも重要となるRe:VIEW記法について解説します。
//}

このように、リード文としてマークアップした内容は、本文に比べて左側の余白が大きくなります。

Re:VIEWでは、リード文のマークアップは文章のどこにでも置くことができます。
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

連番つきリストにするとRe:VIEWは、リストごとに一意な番号を割り振ります。

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
 //}
//}

@<list>{cmd_sample}のマークアップは、次のように出力されます。

//cmd{
$ git add .gitignore
$ git commit -m "first commit"
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

@<list>{quote_sample}のマークアップは次のように出力されます。

//quote{
文章を記述するための軽量マークアップ言語はRe:VIEWの他にもいくつもあります。
たとえば、Wikipediaなどで使われるWiki記法も軽量マークアップ言語です。
IT技術者業界では、他にもMarkdown,reStructuredText,Textileといった例があります。
//}

Re:VIEWは引用の中の改行やスペースをそのまま出力します。
また、引用は本文中からの参照はできません。

=== リンク

URLをリンクとしてマークアップする構文です。

リンクには、出力したときにURLを表示する場合と、しない場合の２つの方法があります。

@<list>{link_sample_with_url}は、URLを表示する場合です。

//list[link_sample_with_url][URLリンク]{
＠<href>{http://techbooster.org}
//}

@<list>{link_sample_with_url}を出力した結果は、"@<href>{http://techbooster.org}"のようにURLがそのまま表示されます。

また@<list>{link_sample}は、URLを表示しない場合です。

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

本文に差し込む画像ファイルは、Re:VIEWファイルがあるディレクトリに@<code>{images}ディレクトリを作成します。
それぞれの画像ファイルは、その画像を差し込む章の名前のディレクトリの下に配置します。

たとえば、@<tt>{markup.re}の章に表示する画像ファイル@<tt>{enlightened.png}の場合、@<tt>{images/markup/enlightened.png}となります。
このことから解るとおり、Re:VIEWでは、異なる章の画像ファイルを直接参照することはできません。
画像ファイルは、章ごとに配置する必要があります。

画像ファイルとして利用できるフォーマットはRe:VIEWで出力する形式に依存しますが、
PNG、JPEG、@<kw>{SVG,Scalable Vector Graphics}など、基本的なフォーマットには対応しています。

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

参照は出力時に「@<img>{enlightened_dup1}」のようにリスト番号に置き換わります。

@<tt>{代替テキスト}は、出力時には無視されます。
基本的にはアスキーアートや文章で画像の説明をして、執筆時にどんな画像を意図しているのか確認するために使いますが、何も書かなくても問題ありません。

==== 連番なしの図

キャプションには、ファイル名や処理など内容を簡潔に記述します。
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

スケールオプションを省略した場合、Re:VIEWは自動で適切なサイズを選択します。
スケールを指定した結果、図が紙面からはみ出る場合もあるので注意してください。

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

Re:VIEW記法では文字を装飾することができます。

文字の装飾は適用したい範囲を@<tt>{＠<修飾子>{...}}で指定するだけです。

また文字の装飾は、本文だけでなくリストや脚注、表などの中でも有効です。
利用頻度の高い文字の装飾について@<table>{character_decorations}にまとめています。

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

== プリプロセッサ命令

Re:VIEWでは、最終的な見た目に影響する記法とは別に、外部の情報を.reファイルに反映するプリプロセッサ命令があります。
プリプロセッサ命令を使うことで、外部ファイルとしているサンプルコードを自動で.reファイル内に反映したりできます。

プリプロセッサ命令を処理するには@<code>{review-preproc}コマンドを使用します。
@<code>{review-preproc}コマンドはPDFのビルド時に自動で実行するようにしておくと便利です。
@<hd>{tips|config_task_runner}を参照してください。

あくまでプリプロセッサ命令は.reファイルの一部を書き換えるだけです。
最終的に.reファイルの内容がビルドされることに変わりはありません。

=== ファイルの内容を読み込む

@<code>{mapfile}命令は、外部ファイルの内容をまるっと読み込みます。
.reファイルで外部ファイルを読み込む箇所に@<code>{#@mapfile(file_name)}と読み込み範囲の終了示す@<code>{#@end}を記述します。
@<code>{review-preproc}コマンドは@<code>{#@mapfile(file_name)}と@<code>{#@end}の間に@<code>{file_name}というファイルを読み込みます。

たとえばサンプルコードfoo.rbを読み込む場合、@<list>{sample_mapfile_before}のように.reファイルに記述します。

//list[sample_mapfile_before][コンパイル前のmapfile記述]{
 //list[sample_code][サンプルコード]{
 #@mapfile(foo.rb)
 #@end
 //}
//}

@<list>{sample_mapfile_before}は@<code>{review-preproc}コマンドの処理後に@<list>{sample_mapfile_after}のようになります。
Re:VIEWは@<code>{#@〜}の行をPDFやHTMLファイルなどの最終的な成果物には出力せず、foo.rbの内容だけを出力します。

//list[sample_mapfile_after][コンパイル後のmapfile記述]{
 //list[sample_code][サンプルコード]{
 #@mapfile(foo.rb)
 puts "foo"
 #@end
 //}
//}

=== ファイルの内容の一部を読み込む

@<code>{maprange}命令は、外部ファイルの一部を読み込みます。
ただし、外部のファイル側に読み込み範囲を示すプリプロセッサ命令を記述しておく必要があります。

範囲を示すには@<code>{#@range_begin(range_name)}と@<code>{#@range_end(range_name)}で範囲を括ります。
@<list>{sample_maprange_source}は@<code>{#@range_begin(range_name)}と@<code>{#@range_end(range_name)}を記述した例です。

//list[sample_maprange_source][maprangeで読み込むsrc.txt]{
 ここは読み込みません。
 #@range_begin(sample)
 ここを読み込みます。
 #@range_end(sample)
 ここは読み込みません。
//}

@<list>{sample_maprange_source}で指定した範囲を読み込むには、.reファイルに@<list>{sample_maprange_before}のように記述します。
ちなみに、@<code>{#@maprange(...)}は@<code>{#@map(...)}と記述しても動作します。

//list[sample_maprange_before][コンパイル前のmaprange記述]{
 //list[sample_code][サンプルコード]{
 #@maprange(src.txt, sample)
 #@end
 //}
//}

@<list>{sample_maprange_before}は@<code>{review-preproc}コマンドの処理後に@<list>{sample_maprange_after}のようになります。

//list[sample_maprange_after][コンパイル後のmaprage]{
 //list[sample_code][サンプルコード]{
 #@maprange(src.txt, sample)
 ここを読み込みます。
 #@end
 //}
//}

=== 外部コマンドの結果を読み込む

@<code>{mapoutput}命令は、外部コマンドの結果を読み込みます。
この命令はRe:VIEWの記法の枠内に囚われず、任意の処理の結果を.reファイルに埋め込めるため便利です。
しかし、あくまでコンパイルするマシンにインストールしているコマンドを使用するため、複数人で共同で執筆する場合は注意が必要です。

たとえば、筆者の環境のjavaのバージョンを自動で埋め込む場合は@<list>{sample_mapoutput_before}のように記述します。

//list[sample_mapoutput_before][java -version]{
 #@mapoutput(java -version 2>&1)
 #@end
//}

@<list>{sample_mapoutput_before}はコンパイル後に@<list>{sample_mapoutput_after}のようになります。

//list[sample_mapoutput_after][java -version]{
 #@mapoutput(java -version 2>&1)
 java version "1.8.0_05"
 Java(TM) SE Runtime Environment (build 1.8.0_05-b13)
 Java HotSpot(TM) 64-Bit Server VM (build 25.5-b02, mixed mode)
 #@end
//}

== 設定ファイルの解説

本節ではRe:VIEWを使う上で必要な各種設定ファイルを解説します。

==={catalog_yml} 章を設定するcatalog.yml

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

==={config_yml} メタデータを記述するconfig.yml

#@# https://github.com/kmuto/review/wiki/config.yml

Re:VIEWでは本を生成（コンパイル）する時のメタデータをYAMLで記述します。
コンパイル時の指定方法は@<hd>{how_to_compile}を参照してください。

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

カスタマイズに当たっては、@<code>{review/lib/review/review.tex.erb}を@<code>{layouts/layout.tex.erb}にコピーして変更すると良いでしょう。

//image[how_to_convert_re_to_pdf2][layout.tex.erbの取り扱い][scale=0.35]{
//}

=={how_to_compile} コンパイルの仕方

=== review-compile

@<code>{review-compile}はReVIEWファイル1つを変換して@<code>{--target}オプションで指定するフォーマットに変換します。

最も簡単な例として、HTMLを出力する例を@<list>{review-compile-example-html-1}に示します。

//list[review-compile-example-html-1][review-compileでHTMLを出力する例。]{
> review-compile --target=html amedama.re
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xmlns:ops="http://www.idpf.org/2007/ops" xml:lang="ja">
<head>
  <meta http-equiv="Content-Type" content="text/html;charset=UTF-8" />
  <meta http-equiv="Content-Style-Type" content="text/css" />
  <meta name="generator" content="ReVIEW" />
  <title>Google Drive APIを使ってファイルをダウンロードする</title>
</head>
<body>
<h1><a id="h38"></a>第38章　Google Drive APIを使ってファイルをダウンロードする</h1>
<p>本章では、PythonスクリプトからGoogle Driveに保存されているファイルを取得する方法を紹介します。Androidとは直接関係ありませんが、同様のAPIをAndroid上で利用する際に参考になるかもしれません。</p>

<h2><a id="h38-1"></a>38.1　収録されている背景</h2>
<p>『Effective Android』同人誌版の執筆が行われていた頃、原稿はGoogle Drive上で管理されていました。一部の技術者の希望によりgitも用いる運用に途中から切り替えたのですが、全員がgitを利用できるわけではないため、原則Google Driveにファイルをアップロードとし、gitは希望者が選択して用いる、という体制になりました<a href="#fn-not_used" class="noteref">*1</a>。</p>
<div class="footnote"><p class="footnote">[<a id="fn-not_used">*1</a>] 本稿執筆時点ではすでにこの体制は終了しています。</p></div>
<p>このとき、管理者がGoogle Drive上のファイルを手動でダウンロードしてgitプロジェクトに取り込んでいると聞き、私はその作業を自動化できるかもしれないと考えました。</p>
<p>Google Drive APIとそのSDKはGoogleから無料で提供されていました。少し調べた結果、今回の目標のためにはそれを使えばよいことが分かりました。</p>
<ul>
<li>What Can You Do with the Drive SDK?<br /><?dtp tab ?>
<a href="https://developers.google.com/drive/about-sdk"
 class="link">https://developers.google.com/drive/about-sdk</a>
</li>
</ul>
... (以下省略)
//}

HTML向け出力は、執筆時に「大まかにどのような出力になるのか」を確認するためによく使われます。
その他にもプレーンテキスト形式にする@<code>{--target=text}、PDFを出力するために必要なTeX形式のファイルを出力する@<code>{--target=latex}、軽量マークアップ言語であるMarkdown形式を出力する@<code>{--target=markdown}などがあります。

//footnote[target_epub_is_not_for_epub][@<code>{--target=epub}は圧縮してEPUB形式とする前のただのHTMLを出力します。]

読者の環境で@<code>{--target}で指定できるフォーマットを調べるには、ReVIEW本体のインストール先にある@<code>{lib/review/???builder.rb}というファイル名のファイルを確認するのが早道です。

//list[supported-target][ReVIEWが対応している出力を確認]{
> ls lib/review/*builder.rb
lib/review/builder.rb        lib/review/ewbbuilder.rb    lib/review/idgxmlbuilder.rb
lib/review/latexbuilder.rb   lib/review/textbuilder.rb   lib/review/epubbuilder.rb
lib/review/htmlbuilder.rb    lib/review/inaobuilder.rb   lib/review/markdownbuilder.rb
lib/review/topbuilder.rb
//}

もっとも、対応する出力形式の多くはReVIEW開発者らが仕事上利用するものであったりするため、執筆時には@<code>{--target=html}を指定する機会が多いと思われます。

@<code>{--check}を指定すると、結果は出力せず、そのフォーマットで入力したファイルが正しく変換出来るかを確認できます。
例えば、@<code>{footnote}と@<code>{fn}で対応がとれているべき場所でとれていない場合、その旨が表示されます。
これもまた執筆中にエラーを前もって避けるために便利です。@<fn>{for_pdf}

//list[unpaired-result][＠<fn>と対応する//footnoteがない場合に発生するエラー]{
> review-compile --check --target=html amedama.re
amedama.re:11: error: ReVIEW::KeyError
//}

//footnote[for_pdf][@<code>{review-pdfmaker}にはこの機能がない一方、前述した通り@<code>{review-compile}では直接はPDFを出力しません。対策として@<code>{review-compile --check --target=latex}とすると、PDFで問題が起こる前に修正できます。出来れば@<code>{review-pdfmaker}を使って対象とする全てのファイルに対してチェックを行える何かが欲しいところです。]

出力されたhtmlを、執筆時のデバッグ用途としてではなく見栄えの良い公開用ファイルにすることもできます。
@<code>{--yaml=(ファイル名)}でReVIEWプロジェクトの設定を読みこませることでスタイルを変更するとよいでしょう。
なお、@<code>{--help}を指定すると、ファイルを読み込んで変換する代わりに対応するオプションの一覧が表示されます。
本章で説明されていないオプションも多々あるので、必要に応じて参照してください。

==== 注意: @<code>{review-compile}ではそのままPDFとEPUBは生成できない

現時点では@<code>{review-compile}からは直接PDFとEPUB形式のファイルを生成することはできません。@<fn>{target_epub_is_not_for_epub}
後述する@<code>{review-pdfmaker}と@<code>{review-epubmaker}をそれぞれ利用してください。

@<code>{review-compile}は主に単一のファイルに対して操作を行う一方、@<code>{review-pdfmaker}と@<code>{review-epubmaker}はReVIEWプロジェクト全体を対象とするため、用途も異なります。
仮に執筆途中のReVIEWファイルのみ、PDFによるフォーマットを確認したい場合、自身でTeX形式から生成する、あるいは逆に全体を@<code>{review-pdfmaker}で生成したあと、該当する章を@<code>{pdktk}等のコマンドで切り出してください。

=== review-pdfmaker

@<code>{review-pdfmaker}はそのプロジェクトのPDFを生成します。
引数としてYAMLファイル（@<code>{config.yml}）を一つ指定します。

//list[review-pdfmaker-example-1][review-pdfmakerの実行例]{
> review-pdfmaker config.yml
(出力省略)
//}

YAMLファイルには本のタイトルや筆者名といった本のメタデータとなる設定を記述しておきます。
その設定の一つ「@<code>{bookname}」が出力されるPDFに対応しています。

@<code>{bookname}で「book」となっている場合、ReVIEWは「@<code>{book-pdf/}」ディレクトリに、途中過程で生成されるファイルを保存した上で、最終的に「book.pdf」を自身のディレクトリに保存します。
仮にこれらのファイル・ディレクトリがすでに存在している場合、ReVIEWはコマンドの実行を中止します。

//list[review-pdfmaker-example-2][すでにPDFを一度作成したあとに再度review-pdfmakerしたときの実行例]{
> review-pdfmaker config.yml
/opt/review/bin/review-pdfmaker:57:in `mkdir': File exists - ./book-pdf (Errno::EEXIST)
        from /opt/review/bin/review-pdfmaker:57:in `main'
        from /opt/review/bin/review-pdfmaker:219:in `<main>'
//}

再度コンパイルする際には、まず手動でPDF（book.pdf）と中間ファイルを収めるディレクトリ（book-pdf/）を削除してから、再度@<code>{review-pdfmaker}を実行します。

@<code>{review-pdfmaker}は内部で@<code>{review-compile --target=latex}を行ったあとに@<code>{platex}や@<code>{dvipdfmx}のようなTeX形式のファイルからPDFへ変換するReVIEW外部のコマンドを実行します。
ReVIEWの外部のコマンドを実行している際には外部のログがそのまま標準出力や標準エラー出力に反映されるため、面食らうかもしれません。

==={rakefile} 脱線: Rakefile で自動化

コンパイル前にbook.pdf等を手動で削除する作業は少々面倒なため、@<code>{Rakefile}@<fn>{about_rakefile}に詳しい人はしばしば以下のような設定を書いています。

//footnote[about_rakefile][今回のように典型的な作業を自動化するツールの一つです。後述する@<code>{review-init}でも生成されています。]

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

==== 執筆時の注意点

@<code>{review-pdfmaker}は、その書籍に含まれるReVIEWファイルに問題があっても、一見正常にPDFを出力することができます。
この場合、コマンド自身は「成功」と報告するのですが、該当する章のデータが勝手に抜け落ちている、という事態につながります。

最も単純な事例は、catalog.ymlの@<code>{CHAPS}での指定を忘れることです。
また、一部の構文エラーについても、そのファイルがなかったこととして、PDFが生成されてしまいます。

これは、複数のReVIEWファイルを用いて原稿執筆している際に若干厄介な問題です。
特に執筆後半では、見栄えの調整のために@<code>{review-compile}よりも頻繁に@<code>{review-pdfmaker}等を実行することがあるのですが、@<code>{review-compile}エラーで中止する代わりに、コマンドはエラーが発生した章を無視してPDFを生成します。

対策として、執筆時には@<code>{review-compile --target=latex --check}を実行して執筆中の原稿単体で発生している問題を排除してから@<code>{review-pdfmaker}を実行することをおすすめします。

章がまるまる抜け落ちることを利用してページ数が減っていないか確認することも出来ます。
参考まで、Linuxの@<code>{pdftk}コマンドでページ数を見る例を示します。

//cmd{
> pdftk book.pdf dump_data_utf8 | grep NumberOfPages
NumberOfPages: 103
//}

=== review-epubmaker

@<code>{review-pdfmaker}同様、@<code>{review-epubmaker}はプロジェクトのメタデータとなるYAMLファイルを引数としてEPUBファイルを生成します。

//list[review-epubmaker-example-1][review-epubmakerの例]{
> review-epubmaker config.yml
(出力省略)
> file book.epub
book.epub: EPUB ebook data
（電子書籍リーダに読み込ませることで内容を確認出来る）
//}

@<code>{review-pdfmaker}同様、参照するYAMLファイル内の@<code>{bookname}を元にして出力されるファイル名が決定されます。

また、コンパイルに関わる注意点も@<code>{review-pdfmaker}と同様です。
PDFとは異なりEPUBでページ数をチェックすることはできませんが、EPUBは実質zip圧縮されたHTMLファイルの塊であるという点を利用して、@<code>{unzip -l}等で自身の原稿ファイルが最終的なEPUBファイルに含まれているかをチェックすることは出来るでしょう。
