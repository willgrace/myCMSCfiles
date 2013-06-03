/* This source code is Copyright (c) Vibrant Media 2001-2010 and forms part of the patented Vibrant Media product "IntelliTXT" (sm). */ 
$iTXT.js.loader["$iTXT.debug.Console"]=true;$iTXT.debug.Console_Load=function(){var undefined;$iTXT.debug.Console=$iTXT.core.Class.create({categoryHash:null,categoryColours:['purple','brown','blue','green','red'],window:null,consoleDocument:null,currentCategory:null,consoleOpen:false,init:function(_options)
{this.options=$iTXT.core.Util.extend({},_options);this.categoryHash={};this.window=window.open('','itxtdebugwin','height=300px,width=700px,resizable=yes,scrollbars=yes,status=no');this.consoleDocument=this.window.document;$iTXT.core.$(this.consoleDocument.body).itxtSetStyle({margin:0,padding:0,height:'100%',width:'100%'});this.rootElement=$iTXT.core.Builder.make("DIV",{id:"itxtConsole"},[],this.consoleDocument);this.consoleDocument.body.appendChild(this.rootElement);var allBtn=$iTXT.core.Builder.make("INPUT",{type:"button",value:"All"},[],this.consoleDocument);var t=this;allBtn.itxtSubscribe("click",function(){t._showTab();});this.btnContainer=$iTXT.core.Builder.make("DIV",{style:"border-bottom: solid 2px #999999; line-height: 1.7em;"},[allBtn],this.consoleDocument);this.headerDiv=$iTXT.core.Builder.make("DIV",{id:"itxtConsoleHdr",style:"width: 100%; background-color: #dddddd;"},[this.btnContainer],this.consoleDocument);this.rootElement.appendChild(this.headerDiv);var rh=this.rootElement.clientHeight-this.headerDiv.offsetHeight;this.panelsDiv=$iTXT.core.Builder.make("DIV",{id:"itxtConsolePnl",style:"height: "+rh+"px; width: 100%; background-color: #eeeeee;"},[],this.consoleDocument);this.rootElement.appendChild(this.panelsDiv);this.allMsgs=$iTXT.core.Builder.make("DIV",{id:"itxtConsoleAllMsgs",style:"height: 100%; width: 100%; overflow: auto;"},[],this.consoleDocument);this.panelsDiv.appendChild(this.allMsgs);$iTXT.core.$(document).itxtSubscribe("$iTXT:console:log",$iTXT.core.Event.bind(this,this._log));$iTXT.core.$(this.window).itxtSubscribe("resize",$iTXT.core.Event.bind(this,this._resize));this._resize();this.consoleOpen=true;},_log:function(e)
{if(!e.data||!this.consoleOpen)
return;try
{var d=new Date();var dateStr=this._formatDate(d);var msg=e.data.msg||"";var cat=this._getCategory(e.data.cat||"General");var line=$iTXT.core.Builder.make("DIV",{style:("padding: 2px; font-family: 'Lucida Grande', Verdana; font-size: 10px; color: "+cat.c+";")},[$iTXT.core.Builder.make("B",{},["["+dateStr+"] "],this.consoleDocument),msg],this.consoleDocument);this.allMsgs.itxtAppendChild(line);line.scrollIntoView(false);if(cat.element)
{var line2=$iTXT.core.Builder.make("DIV",{style:("padding: 2px; font-family: 'Lucida Grande', Verdana; font-size: 10px; color: "+cat.c+";")},[$iTXT.core.Builder.make("B",{},["["+dateStr+"] "],this.consoleDocument),msg],this.consoleDocument);cat.element.itxtAppendChild(line2);line2.scrollIntoView(false);}}
catch(ex)
{this.consoleOpen=false;}},_getCategory:function(name)
{if(undefined==this.categoryHash[name])
{this.categoryHash[name]=this._createCategory(name);}
return this.categoryHash[name];},_createCategory:function(name)
{var newC=this._getColour();var catDiv=$iTXT.core.Builder.make("DIV",{id:"itxtConsoleCat"+name,style:"display: none; height: 100%; width: 100%; overflow: auto;"},[],this.consoleDocument);this.panelsDiv.appendChild(catDiv);var catBtn=$iTXT.core.Builder.make("INPUT",{type:"button",value:name,style:"font-weight: bold; color: "+newC},[],this.consoleDocument);this.btnContainer.appendChild(catBtn);var t=this;catBtn.itxtSubscribe("click",function(){t._showTab(name);});var cob={c:newC,name:name,element:catDiv};return cob;this._resize();},_getColour:function()
{if(this.categoryColours.length>0)
{return this.categoryColours.pop();}
return'black';},_resize:function()
{var winSize=$iTXT.core.Util.getWindowSize(this.window,this.consoleDocument);this.rootElement.itxtSetStyle({overflow:'hidden',width:winSize.width+"px",height:winSize.height+"px"});var rh=this.rootElement.clientHeight-this.headerDiv.offsetHeight;this.panelsDiv.itxtSetStyle({height:rh+"px"});for(var catName in this.categoryHash)
{var cat=this.categoryHash[catName];cat.element.itxtSetStyle({height:rh+"px"});}
this.allMsgs.itxtSetStyle({height:rh+"px"});},_showTab:function(name)
{if(this.currentCategory!=name)
{for(var catName in this.categoryHash)
{var cat=this.categoryHash[catName];cat.element.itxtHide();}
this.allMsgs.itxtHide();if(name&&""!=name)
{this.categoryHash[name].element.itxtShow();}
else
{this.allMsgs.itxtShow();}
this.currentCategory=name;this._resize();}},_formatDate:function(d)
{var h=d.getHours();var m=d.getMinutes();var s=d.getSeconds();var ms=d.getMilliseconds();return h+":"+m+":"+s;}});}
$iTXT.js.loader["$iTXT.debug.Util"]=true;$iTXT.debug.Util_Load=function()
{var undefined;$iTXT.debug.Util={ECH_EVENTS_TIME:1,ECH_EVENTS_DUMP:2,ECH_ASSESS_DUMP:4,HL_COL_INIT:'#FCB514',HL_COL_SKIP:'green',HL_COL_EXCLUDE:'red',HL_COL_CONTENT:'blue',hilite:function(n,c)
{if($iTXT.cnst.DEBUG_LEVEL>0&&$iTXT.cnst.DEBUG_HILITE>0&&$iTXT.core.Util.isElement(n)&&$iTXT.core.Util.isString(c))
{try
{n.style.borderStyle='solid';n.style.borderWidth='2px';n.style.borderColor=c;}
catch(x)
{}}},msg:function(m,l)
{if($iTXT.core.Util.isUndefined($iTXT.cnst.DEBUG_LEVEL))
{$iTXT.cnst.DEBUG_LEVEL=0;}
if($iTXT.core.Util.isUndefined($iTXT.cnst.DEBUG_TO_FIREBUG))
{$iTXT.cnst.DEBUG_TO_FIREBUG=0;}
if($iTXT.cnst.DEBUG_LEVEL<=0&&$iTXT.cnst.DEBUG_TO_FIREBUG<=0)
{return;}
if(1===$iTXT.cnst.DEBUG_TO_FIREBUG&&!$iTXT.core.Util.isUndefined(console))
{console.info(m.replace(/\&nbsp\;/g,' ').replace(/<br(\s*\/)>/gi,'\n').replace(/<[^>]+>/g,''));}
else
{itxtFeedback(m,l);}}};}