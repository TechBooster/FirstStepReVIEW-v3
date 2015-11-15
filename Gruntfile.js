module.exports = function (grunt) {
	grunt.initConfig({
		clean: {
			review: {
				src: [
					'articles/C89-FirstStepReVIEW-v2-pdf/',
					'articles/*.pdf',
					'articles/*.epub',
					'articles/*.html',
					'articles/*.xml',
					'articles/*.txt'
				]
			}
		},
		exec: {
			preprocess: {
				cwd: "./articles",
				cmd: function () {
					var command = "bundle exec review-preproc-peg";
					var files = [
						"articles"
					];
					var exec = command + " -r --tabwidth=2 *.re";
					console.log(exec);
					return exec;
				}
			},
			compile2text: {
				cwd: "./articles",
				cmd: function () {
					return "bundle exec review-compile-peg --all --target=text";
				}
			},
			compile2html: {
				cwd: "./articles",
				cmd: function () {
					return "bundle exec review-compile-peg --all --target=html --stylesheet=style.css --chapterlink";
				}
			},
			compile2latex: {
				cwd: "./articles",
				cmd: function () {
					return "bundle exec review-compile-peg --all --target=latex --footnotetext";
				}
			},
			compile2idgxml: {
				cwd: "./articles",
				cmd: function () {
					return "bundle exec review-compile-peg --all --target=idgxml";
				}
			},
			compile2pdf: {
				cwd: "./articles",
				cmd: function () {
					return "bundle exec review-pdfmaker-peg config.yml";
				}
			},
			compile2epub: {
				cwd: "./articles",
				cmd: function () {
					return "bundle exec review-epubmaker-peg config.yml";
				}
			}
		}
	});

	function generateTask(target, pretask) {
		pretask = pretask || [];
		return ['clean', 'exec:preprocess', 'exec:compile2' + target];
	}

	grunt.registerTask(
		'default',
		"原稿をコンパイルしてPDFファイルにする",
		"pdf");

	grunt.registerTask(
		'text',
		"原稿をコンパイルしてTextファイルにする",
		generateTask("text"));

	grunt.registerTask(
		'html',
		"原稿をコンパイルしてHTMLファイルにする",
		generateTask("html"));

	grunt.registerTask(
		'idgxml',
		"原稿をコンパイルしてInDesign用XMLファイルにする",
		generateTask("idgxml"));

	grunt.registerTask(
		'pdf',
		"原稿をコンパイルしてpdfファイルにする",
		generateTask("pdf"));

	require('load-grunt-tasks')(grunt);
};
