/*
|--------------------------------------------------------------------------
| Global requires
|--------------------------------------------------------------------------
|
| Run 'npm install' to install all node modules that are required here.
| The npm modules are pulled in from the node_modules folder
|
*/

	var gulp 		= require('gulp');
	var less 		= require('gulp-less');
	var path 		= require('path');
	var browserSync = require('browser-sync').create();
	var fs 			= require("fs");
	var browserify 	= require('browserify');
	var vueify 		= require('vueify');
	var babelify 	= require('babelify');
	var plumber 	= require('gulp-plumber');


/*
|--------------------------------------------------------------------------
| Gulp tasks
|--------------------------------------------------------------------------
|
| All gulp tasks are specified here
|
*/
 
	// Less compiler
	gulp.task('less', function () {
	  return gulp.src('./less/**/*.less')
	  	.pipe(plumber())
	    .pipe(less({
	      paths: [ path.join(__dirname, 'less', 'includes') ]
	    }))
	    .pipe(gulp.dest('./css'))
	    .pipe(browserSync.reload({ stream: true}));
	});

	// Browsersync proxy(uses an existing server)
    gulp.task('browser-sync', function() {
        browserSync.init({
            proxy: "vakver.dev",
            // enable shared interactions between devices
            ghostMode: true,
            
            /* public url prefix */
            // tunnel: "waddenribtochten",
             
            /* online */
            online: true,

            /* Don't show any notifications in the browser. */
            notify: false,

            /* typekit prefixer */
            xip: false,

            /* Stop the browser from automatically opening */
			open: false
        });
    });


    // Added babelify transform as well because our entry file contains ES2015
    gulp.task('browserify', function() {
    	browserify('./js/entry.js')
	  	.transform(vueify)
	  	// optionally add babelify if vuex is implemented
	  	.transform(babelify)
	  	.bundle()
	  	.pipe(fs.createWriteStream('./js/bundle.js'))
    });

/*
|--------------------------------------------------------------------------
| File watcher
|--------------------------------------------------------------------------
|
| The file watcher will watch a folder for file changes whenever a change
| has been made in the specified folder a gulp task or array of tasks 
| will be called.
|
*/

    // Rerun the task when a file changes
	gulp.task('watch', function() {
	  gulp.watch('./less/**/*.less', ['less']);
	  gulp.watch('./js/entry.js', ['browserify']);
	  gulp.watch('./js/**/*.vue', ['browserify']);
	});

/*
|--------------------------------------------------------------------------
| Default gulp taskrunner
|--------------------------------------------------------------------------
|
| Whenever 'gulp' is called from the commandline this is the entrypoint
| default task being called. The second argument takes a task or array
| of tasks that are called when this task runs.
|
*/

	gulp.task('default', [
		'watch', 
		'less',
		'browser-sync',
		'browserify'
	]);



