/*!
 * pervert.js Performance Visualization and Error Remediation Toolkit
 * frontend
 *
 * Copyright 2011, Niels Joubert, Eric Schkufza
 *
 * Dependencies: 
 *   - jQuery
 *
 * This uses the Revealing Module pattern.
 * Do NOT use this pattern if you create lots of objects,
 * it is for revealing a single module with a public API.
 * If you create many objects, functions should live on prototypes,
 * so that you do not duplicate function implementations every time you create an object
 */

(function(global){ 
  var pervert = function(exec) {
    return Pervert(exec);
  }

  var jqXHRQueue = function() {
    self = this;
    self.__data = [];
    self.add = function(xhr,settings) { self.__data.push(xhr); };
    self.complete = function(xhr,success) { 
      var idx = self.__data.indexOf(xhr);
      if (idx!=-1) self.__data.splice(idx, 1);
    };
    self.abort = function() { $.each(self.__data, function(xhr) { xhr.abort(); }); };
    self.ajax = function(path, settings) {
      $("#right-sidebar").html(self.__data.length);
      settings["complete"] = self.complete;
      var t = $.ajax(path, settings);
      self.add(t);
      return t; 
    } 
  }

  var Pervert = function(exec) {
    var self = this;
    var __exec = exec;
    
    var __ajaxqueue = new jqXHRQueue(); 
    
    //set up event handlers:
    
    
    //private functions:
    function getListOfExecs() {
      __ajaxqueue.ajax('/pp/list', {
        success: function(data) { $("#right-sidebar").html(JSON.stringify(data)); }
       });
    }
     
    // Public API:  
    var init = function() {
      getListOfExecs();
      
    }
    
    var remove = function() {
      
    } 

    
    return {
      init: init,
      remove: remove
    }
    
  }
  
  pervert.VERSION = '0.0.1';
  
  if (global.pervert) {
    throw new Error("pervert has already been defined.")
  } else {
    global.pervert = pervert;
  }
  
})(window);