"use strict";

let fs = require("fs");
let yaml = require("js-yaml");

const articles = "articles";
const publish = 'publish';
const bookConfig = yaml.safeLoad(fs.readFileSync(`${articles}/config.yml`, "utf8"));

const reviewPrefix = process.env["REVIEW_PREFIX"] || "bundle exec ";
const reviewPostfix = process.env["REVIEW_POSTFIX"] || "";             // REVIEW_POSTFIX="-peg" npm run pdf とかするとPEGでビルドできるよ
const reviewPreproc = `${reviewPrefix}review-preproc${reviewPostfix}`;
const reviewCompile = `${reviewPrefix}review-compile${reviewPostfix}`;
const reviewWebMaker = `${reviewPrefix}review-webmaker${reviewPostfix}`;
const reviewPdfMaker = `${reviewPrefix}review-pdfmaker${reviewPostfix}`;
const reviewEpubMaker = `${reviewPrefix}review-epubmaker${reviewPostfix}`;

module.exports = grunt => {
	grunt.initConfig({
		clean: {
			review: {
				src: [
					`${articles}/${bookConfig.bookname}-*/`, // pdf, epub temp dir
					`${articles}/*.pdf`,
					`${articles}/*.epub`,
					`${articles}/*.html`,
					`${articles}/*.xml`,
					`${articles}/*.txt`
				]
			},
			publish: {
				src: `${publish}/`
			}
		},
		sass: {
			dist: {
				options: {
					bundleExec: true,
					sourcemap: 'none'
				},
				files: {
					'articles/style.css': 'articles/style.scss',
					'articles/style-web.css': 'articles/style-web.scss',
				}
			}
		},
		copy: {
			publish: {
				files: [
					{expand: true, cwd: `${articles}/webroot/`, src: ['**'], dest: `${publish}/`}
				]
			}
		},
		exec: {
			preprocess: {
				cwd: articles,
				cmd: `${reviewPreproc} -r --tabwidth=2 *.re`
			},
			compile2text: {
				cwd: articles,
				cmd: `${reviewCompile} --target=text`
			},
			compile2html: {
				cwd: articles,
				cmd: `${reviewCompile} --target=html --yaml=config.yml --chapterlink --footnotetext`
			},
			compile2latex: {
				cwd: articles,
				cmd: `${reviewCompile} --target=latex --footnotetext`
			},
			compile2idgxml: {
				cwd: articles,
				cmd: `${reviewCompile} --target=idgxml`
			},
			compile2web: {
				cwd: articles,
				cmd: `${reviewWebMaker} config.yml`
			},
			compile2pdf: {
				cwd: articles,
				cmd: `${reviewPdfMaker} config.yml`
			},
			compile2epub: {
				cwd: articles,
				cmd: `${reviewEpubMaker} config.yml`
			}
		}
	});

	function generateTask(target, pretask) {
		pretask = pretask || [];
		return ["clean"].concat(pretask).concat(["exec:preprocess", `exec:compile2${target}`]);
	}

	grunt.registerTask(
		"default",
		"原稿をコンパイルしてPDFファイルにする",
		"pdf");

	grunt.registerTask(
		"text",
		"原稿をコンパイルしてTextファイルにする",
		generateTask("text"));

	grunt.registerTask(
		"html",
		"原稿をコンパイルしてHTMLファイルにする",
		generateTask("html", ["sass"]));

	grunt.registerTask(
		"idgxml",
		"原稿をコンパイルしてInDesign用XMLファイルにする",
		generateTask("idgxml"));

	grunt.registerTask(
		"web",
		"原稿をコンパイルしてwebページにする",
		generateTask("web", ["sass"]).concat(['copy:publish']));

	grunt.registerTask(
		"pdf",
		"原稿をコンパイルしてpdfファイルにする",
		generateTask("pdf"));

	grunt.registerTask(
		"epub",
		"原稿をコンパイルしてepubファイルにする",
		generateTask("epub"));

	require('load-grunt-tasks')(grunt);
};
