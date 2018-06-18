function scale_img(percentage) {
    var url = this;
    return '<img src="' + url + '" style="width: ' + percentage + '" />';
    // Usage:
    //   ![:scale 50%](image.jpg)
    // Outputs:
    //   <img src="image.jpg" style="width: 50%" />
}

function loadUrl (url) {
    var xhr = new XMLHttpRequest();
    // Make async...
    xhr.open('GET', url, false);
    xhr.send();
    return xhr.responseText;
}

function addPreamble(options) {
    
    return options;
}

function addStyle() {
    var fileref = document.createElement("link");
    fileref.setAttribute("rel", "stylesheet");
    fileref.setAttribute("type", "text/css");
    fileref.setAttribute("href", "../epcc/style.css");
    
    document.getElementsByTagName("head")[0].appendChild(fileref)
}

function create(options) {
    options = options || {};
    var body;
    
    epcc = loadUrl("/epcc/template.md");
    
    if (options.sourceUrl) {
	body = loadUrl(options.sourceUrl);
	delete options.sourceUrl;
	
    } else if (!options.hasOwnProperty('source')) {
	
	sourceElement = this.dom.getElementById('source');
	if (sourceElement) {
	    body = unescape(sourceElement.innerHTML);
	    sourceElement.style.display = 'none';
	}
    }

    options.source = epcc + body;
    
    return remark.create(options);
}

function install_theme() {
    remark.macros.scale_img = scale_img;
    remark.create_themed = create;
    addStyle();
}

install_theme();
