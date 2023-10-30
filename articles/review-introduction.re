={review-introduction} Re:VIEW記法を理解する

本章ではRe:VIEWの記法を紹介します。
執筆にあたって適切なマークアップを選択できるよう、利用頻度の高いRe:VIEW記法について扱います。

Re:VIEW記法は、文章を書き、見出しやコードなどをマークアップするための記法です。
たとえば技術書では、文章や単語を強調したいときに@<strong>{太字}にしたり、クラスやメソッドの名前を記述する場合、@<code>{等幅フォント}にしたりと、
視覚的な差別化が行われています。
#@# REVIEW vvakame i とか tt は見た目の情報なので code とかを使ったほうがいいような…。
#@# mhidaka @<tt>{}はいまのところファイル名、Pathのマークアップにのみ利用している。@<b>は@<strong>と@<em>が類似に存在してるんだけどweightの使い分けがどうしようかな
#@# @<b>はフォント指定のbold、著者が強調したいときは現時点では@<strong>で統一しています。

#@# prh:disable
Re:VIEW記法でマークアップすることで文章の構造や見た目を記述できます。
マークアップの巧拙が表現力の差となります。そして、より良い表現は、読者にとってより良い情報になります。

== 見出し

見出しは、@<code>{=}（イコール）から始めて、キャプションを続けます。

@<code>{=}は、必ず行頭から開始します。
また、@<code>{=}の後ろには、必ず半角スペースを入れます。

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

== 段落と改行

文章と文章の間に空行を挟むと、それぞれが個別の段落として処理されます。


２つ以上空行を入れても段落分けには影響しません。


また、Re:VIEWでは、
空行を挟まない改行は無視され、出力には影響しません。      １つ以上の半角スペースも、出力には影響しません。

＠<br>{}を使うと、強制的に@<br>{}
改行@<br>{}
できます。

//emlist[段落を含む文章]{
Re:VIEW記法の段落は、空行を挟んで文章を続けます。


２つ以上空行を入れても段落分けには影響しません。

また、Re:VIEWでは、
空行を挟まない改行は無視され、出力には影響しません。      １つ以上の半角スペースも、出力には影響しません。

＠<br>{}を使うと、強制的に＠<br>{}
改行＠<br>{}
できます。
//}

== コメント

#@#この行はコメントです。
行が@<code>{#@#}から始まる場合、その行についてはコメントとして扱われ、最終出力には影響しません。

//emlist[コメント]{
#＠# この行はコメントです。
行が@<code>{#@#}から始まる場合、その行についてはコメントとして扱われ、最終出力には影響しません。
//}

複数行をコメントとして扱うには、すべての行に@<code>{#@#}を含めるか次の記法を利用します。

//emlist[複数行コメント]{
  //comment{
    コメントだよ
  //}
//}

//comment{
  コメントだよ
//}

== 箇条書き

項目を列挙する際に、箇条書きを利用できます。
Re:VIEWは、「番号なし箇条書き」と「番号つき箇条書き」に対応しています。

=== 番号なし箇条書き

*に続けて項目を記述すると箇条書きになります。
番号なし箇条書きはツリー構造も表現でき、*の数がそのまま深さになります。

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

=== 番号あり箇条書き

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
しかし、行の追加や削除の際は、可能な限り番号を書き換えることをお勧めします。
本文中で3番は〜などと言及したときに文書上の項番が中途半端に振られていると、ミスの原因となるからです。

== リスト

プログラムコードなど、本文とは分けて掲載する内容を「リスト」と言います。
リストの中の改行やスペースはそのまま出力されます。

//list[list_sample][通し番号の割り当て＋キャプションを表示]{
また、画像やプログラムリストを掲載する場合、視覚的に区別しやすくし、本文に対し適切な余白をとり、適切な場所に配置することも大切です。
//}

Re:VIEWのリストには、連番つきと連番なしの２種類、行番号の有無を含めると計４種類があります。

//table[list_table][リストの区分]{
.	行番号なし	行番号あり
-------------------------
連番つき	list	listnum
連番なし	emlist	emlistnum
//}

=== リストの参照

文章中でコード例や図版を挿入したとき、文中からそれらを参照するために「リスト 2.1」などと番号を振る必要がありますが、
Re:VIEWにはリストや図版の採番を自動的にするための仕組みがあります（@<list>{list_refs}）。

//list[list_refs][連番つきリストは通し番号で参照可能]{
このリストは参照されています。
//}

連番つきリストにするとRe:VIEWは、リストごとに一意な番号を割り振ります。
一方、連番なしリストは、リストに番号を割り当てず、本文からは参照できません。

一般的にソースコードリストのように本文から参照する場合には、連番付きリスト（@<code>{list}）を推奨します。
参照関係が明らかな場合のみ、連番なしリスト（@<code>{emlist}）を利用するといいでしょう。


=== 連番つきリスト

連番つきのリストです。

キャプションには、ソースコードファイル名や処理内容など、リストの示す内容を簡潔に記述します。
連番付きリストのキャプションは省略できません。

//list[list_sample_with_seq2][連番付きリスト]{
 //list[identifier][連番付きリストのキャプション]{
  ...ソースコード等...
 //}
//}

@<list>{list_sample_with_seq2}のマークアップは、次のように出力されます。

//list[identifier_dummy1][連番付きリストのキャプション]{
 ...ソースコード等...
//}

＠<list>{@<code>{identifier}}で、@<kw>{identifier,識別子}が示すリストを参照できます。
参照は、出力時に「@<list>{list_sample_with_seq2}」のようにリスト番号に置き換わります。

=== 連番なしリスト

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

連番なしリストは、本文中からの参照はできません。

=== 連番つきリスト（行番号有り）

連番付きのリストで、かつ自動的に行番号が表示されます。

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

＠<list>{@<code>{identifier}}で、@<kw>{identifier,識別子}が示すリストを参照できます。
参照は、出力時に「@<list>{listnum_sample_with_seq2}」のようにリスト番号に置き換わります。

=== 連番なしリスト（行番号有り）

連番なしのリストで、かつ自動的に行番号が表示されます。

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

行番号をつける場合は、通常、本文からの参照・説明を意図していることが多く、利用頻度がきわめて低い構文です。

=={commandline} コマンドライン

コマンドラインの入出力などを示す構文です。本書を含め多くの書籍では黒っぽい背景色が採用されており、
わかりやすい出力が使われます。

//list[cmd_sample][コマンドラインの例]{
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

== 引用

ウェブサイトや書籍などから引用した文章を示す構文です。

//list[quote_sample][引用文]{
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

== リンク

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
最終的に印刷する場合は、URLを表示する方法が適しています。後述する脚注で使われることが多いでしょう。

== 図

写真や挿絵などを「図」として、本文中に差し込むことができます。

差し込む写真や図面などは別ファイルで保存しておき、本文中に参照を記述します。

=== 画像ファイル

本文に差し込む画像ファイルは、Re:VIEWファイルがあるディレクトリに@<code>{images}ディレクトリを作成します。
それぞれの画像ファイルは、その画像を差し込む章の名前のディレクトリの下に配置します。

たとえば、@<tt>{markup.re}の章に表示する画像ファイル@<tt>{image_sample.png}の場合、@<tt>{images/markup/image_sample.png}となります。
このことから解るとおり、Re:VIEWでは、異なる章の画像ファイルを直接参照することはできません。
画像ファイルは、章ごとに配置する必要があります。

画像ファイルとして利用できるフォーマットはRe:VIEWで出力する形式に依存しますが、
PNG、JPEG、@<kw>{SVG,Scalable Vector Graphics}など、基本的なフォーマットには対応しています。

#@# REVIEW vvakame 画像の対応フォーマットとか○○がインストールしてあると☓☓も使える…とかはいらない？

=== 連番つきの図

キャプションには、ファイル名や処理内容など、内容を簡潔に記述します。
キャプションは省略できません。

//list[image_sample_with_seq][連番つきの図]{
 //image[image_sample][連番つきの図]{
 ...代替テキスト等...
 //}
//}

@<list>{image_sample_with_seq}のマークアップは、次のように出力されます。

//image[image_sample_dup1][連番つきの図]{
//}

＠<img>{@<code>{identifier}}で、本文から@<kw>{identifier,識別子}が示す図を参照できます。

参照は出力時に「@<img>{image_sample_dup1}」のようにリスト番号に置き換わります。

@<code>{代替テキスト}は、出力時には無視されます。
基本的にはアスキーアートや文章で画像の説明をして、執筆時にどんな画像を意図しているのか確認するために使いますが、何も書かなくても問題ありません。

=== 連番なしの図

キャプションには、ファイル名や処理など内容を簡潔に記述します。
キャプションは省略できません。

//list[image_sample_with_no_seq][連番なしの図]{
 //indepimage[image_sample][連番なしの図]
//}

@<list>{image_sample_with_no_seq}のマークアップは、次のように出力されます。

//indepimage[image_sample][連番なしの図]

連番なしの図は、本文中からの参照はできません。また、@<tt>{代替テキスト}は指定できません。

=== 図のサイズを指定する

スケールオプションで図の表示倍率を指定することができます。

スケールオプションは、@<code>{image}、@<code>{indepimage}に括弧[]を追加して、@<code>{scale=}に続いて表示倍率を指定します。

表示倍率は、@<code>{1.0}を紙面の横幅いっぱいとして、@<code>{0.0}を下限として指定できます。

//list[scaled_image_sample_with_seq][連番付きの図]{
 //image[image_sample][表示倍率50%]@<b>{[scale=0.5]}{
 ...代替テキスト等...
 //}
//}

//image[image_sample_dup2][表示倍率50%][scale=0.5]{
...代替テキスト等...
//}

//list[scaled_image_sample_with_no_seq][連番なしの図]{
 //indepimage[image_sample][表示倍率25%]@<b>{[scale=0.25]}
//}

//indepimage[image_sample][表示倍率25%][scale=0.25]

スケールオプションを省略した場合、Re:VIEWは自動で適切なサイズを選択します。

== 表

罫線で区切られた表をマークアップする構文です。

Re:VIEWでは、行は改行、セルとセルの間にはタブで区切ります。

空白のセルは、ピリオド（@<code>{.}）を入力します。
セルにピリオドを表示したい、またはセルの内容をピリオドから始めたい場合、ピリオドを２つ続けて（@<code>{..}）入力します。

また、@<code>{-------------}で区切ることで、ヘッダの行を明確に指定できます。

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

＠<table>{@<code>{identifier}}で、@<kw>{identifier,識別子}が示す表を参照できます。
参照は、出力時に「@<table>{table_sample}」のように表番号に置き換わります。

== 脚注

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

＠<fn>{@<code>{identifier}}で、@<kw>{identifier,識別子}が示す脚注を参照できます。

本文から参照すると、脚注番号が付記されます@<fn>{about_footnote}。

== リード文

ひとまとまりの文章の内容を、簡単に説明する短い文章を「リード文」と言います。
#@# REVIEW vvakame この本の全ての章にリード文入れたほうがいいっすかね？

//list[sammple_lead][リード文]{
 //lead{
 本章ではRe:VIEWで執筆をする上で最初に覚えるRe:VIEW記法について解説します。
 //}
//}

@<list>{sammple_lead}のマークアップは、次のように出力されます。

//lead{
本章ではRe:VIEWで執筆をする上で最初に覚えるRe:VIEW記法について解説します。
//}

このように、リード文としてマークアップした内容は、本文に比べて左側の余白が大きくなります。

Re:VIEWでは、リード文のマークアップは文章のどこにでも置けます。
しかし、基本的には見出し、特に章見出しのすぐあとに置くことを想定しています。

== 文字の装飾

Re:VIEW記法では文字を装飾できます。

文字の装飾は適用したい範囲を@<code>{＠<修飾子>{...}}で指定するだけです。

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
＠<code>{文字列}	コードに利用	@<code>{abcdefg}
//}

＠<kw>は初出の単語で利用するとよいでしょう。またソースコード上の関数や変数名といった表記は＠<tt>を使っても同じ装飾表現を得られますが
＠<code>を利用してください。変換前の文章では＠<code>のほうが圧倒的に著者の意図をくみとりやすく、校正や編集で装飾のゆらぎを検出しやすくなります。

== 参照

他の見出しを参照し、文章中で利用できます。
参照を使わず、見出しのキャプションや番号を直接記述した場合、変更が発生するたび関連箇所を漏れなく探し出し、すべてに修正を加えなくてはなりません。

見出しの参照を使うと、章や節の順番の入れ替え、タイトルの変更などは自動的に反映されます。
見出しの参照は、大きく「章の参照」と「節の参照」の２つに分類できます。

=== 章の参照

章を参照する構文です。

@<list>{refer_chap}は、３つとも@<chapref>{writing-book}を参照しています。

//list[refer_chap][章の参照]{
＠<title>{writing-book}

＠<chap>{writing-book}

＠<chapref>{writing-book}
//}

@<code>{title}は、その章のキャプションになります（@<title>{writing-book}）。

@<code>{chap}は、その章の見出し番号になります（@<chap>{writing-book}）。

@<code>{chapref}は、その章の見出し番号とキャプションになります（@<chapref>{writing-book}）。

これらの構文の参照先には、Re:VIEWの章の識別子を指定します。

章の識別子は、Re:VIEWの章のファイル名から拡張子@<tt>{.re}を取り除いた名前です。
たとえば、@<tt>{writing-book.re}の章を参照する場合、@<code>{writing-book}が識別子になります。

=== 節の参照

章より一段深い階層にある「節」を参照する構文です（@<list>{refer_section}）。

//list[refer_section][見出しの参照]{
＠<hd>{見出し}

＠<hd>{writing-book|Re:VIEWの特色}
//}

同じ章の節を参照する場合、参照先には、節のキャプションだけを記載します。

異なる章の見出しを参照する場合、章の識別子を指定した上で、縦棒@<code>{|}で区切って節のキャプションを記述します。

章の識別子は、Re:VIEWの章のファイル名から拡張子@<tt>{.re}を取り除いた名前です。
たとえば、@<tt>{writing-book.re}の章を参照する場合、@<code>{writing-book}が識別子になります。

=== 見出しラベル

節の参照では、見出しのキャプションをそのまま記述するので、キャプションを変更したときに参照を更新する必要があります。

Re:VIEWでは、見出しキャプションとは別に、参照用のラベルを指定できます。

//list[section_label][見出しの参照用ラベル]{
 =={commandline} コマンドライン
//}

@<list>{section_label}の括弧{}の中が節の識別子になり、@<list>{refer_section_label}のように参照します。

//list[refer_section_label][見出しの参照]{
＠<hd>{commandline}
//}

通常の節の参照同様、違う章の節を参照できる優れものです。


==[column] ブロック命令とインライン命令

Re:VIEW記法は「ブロック命令」と「インライン命令」の２つに分類できます。
#@# REVIEW vvakame インライン記法とブロック記法のほうが好きだな… どこからの表現だろう

==== ブロック命令

#@# REVIEW vvakame ブロック記法についてはインライン記法より先に書くべきだと思う。インライン記法がなくてもemlistなどで技術書は書けるが、逆は真ではないからだ。

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

==== インライン命令

インライン命令は@<code>{＠<命令>{...}}のように、@<kw>{＠,アットマーク}に続けて括弧<>内に命令名を指定します。
続く括弧{}の中が、インライン命令の効果が及ぶ範囲になります。

インライン命令は、文章の装飾やリストや図の参照など表示や内容に影響します。
文中に直接記入することができますが、改行をまたぐことやインライン命令のネストはできません。

==[/column]
