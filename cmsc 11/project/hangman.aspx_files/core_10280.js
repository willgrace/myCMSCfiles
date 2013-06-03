/* This source code is Copyright (c) Vibrant Media 2001-2010 and forms part of the patented Vibrant Media product "IntelliTXT" (sm). */ 
$iTXT.js.loader["$iTXT.core.Util"]=true;$iTXT.core.Util_Load=function()
{var undefined;$iTXT.core.Util={callbackID:0,args:function(args)
{var rA=[];for(var i=0;i<args.length;i++)
{rA[i]=args[i];}
return rA;},extend:function(dest,src)
{for(var p in src)
{if(undefined!=src[p])
{dest[p]=src[p];}}
return dest;},extendObjectArray:function(dest,src,prop)
{dest=dest.reverse();src=src.reverse();var pA=[];for(var s=0;s<src.length;s++)
{if(src[s]&&!this.isUndefined(src[s][prop]))
{pA.push(src[s][prop]);}}
for(var d=0;d<dest.length;d++)
{if(dest[d]&&!this.isUndefined(dest[d][prop])&&!this.inArray(pA,dest[d][prop]))
{src.push(dest[d]);}}
return src.reverse();},isElement:function(o)
{return!!(o&&o.nodeType==1);},isAttribute:function(o)
{return!!(o&&o.nodeType==2);},isTextNode:function(o)
{return!!(o&&(o.nodeType==3));},isCDATA:function(o)
{return!!(o&&(o.nodeType==4));},isDOMNode:function(o)
{return!!(o&&(this.isElement(o)||this.isAttribute(o)||this.isTextNode(o)||this.isCDATA(o)));},isFunc:function(o)
{return typeof o==="function";},isArray:function(o)
{return this.getClass(o)==="Array";},isString:function(o)
{return this.getClass(o)==="String";},isNumber:function(o)
{return!isNaN(o);},isObject:function(o)
{return this.isUndefined(o)?false:(this.getClass(o)==="Object");},isUndefined:function(o)
{return typeof o===typeof undefined;},isURL:function(s)
{if(!this.isString(s))
{return s;}
else
{var m=s.match("^(https?|mailto|ftp|wais|file|gopher|telnet)://[A-Za-z0-9-_]+\\.[A-Za-z0-9-_%&\?\/.=]+$");return(null==m)?false:true;}},cleanString:function(s)
{if(!this.isString(s))
{return s;}
else
{return s.replace(/\t/g,' ').replace(/\n/g,'').replace(/\r/g,'').replace(/^\s+/g,'').replace(/\s+$/g,'');;}},getClass:function(o)
{return Object.prototype.toString.call(o).match(/^\[object\s(.*)\]$/)[1];},dropScript:function(src,loadFunc)
{if('string'!=typeof src||!src.match(/^http/)){return;}
try
{var newS=document.createElement('script');var cbFunc=this.callbackFunction(loadFunc,newS);if(src.indexOf('?')!=-1)
{src+="&jscallback="+cbFunc;}
else
{src+="?jscallback="+cbFunc;}
newS.src=src;newS.type='text/javascript';var b=document.getElementsByTagName('body')[0];b.insertBefore(newS,b.firstChild);}
catch(e)
{alert(e);}},callbackFunction:function(f,src)
{var cbName="callback"+(this.callbackID++);$iTXT.js[cbName]=function()
{if(f)
{if(src)
{f.apply(src);}
else
{f();}}}
return"$iTXT.js."+cbName;},getQueryParams:function(srcUrl)
{if(srcUrl.indexOf('?')==-1)
{return{};}
var params={};var qs=srcUrl.substring(srcUrl.indexOf('?')+1);var pairs=qs.split('&');for(var i=0;i<pairs.length;i++)
{var keyPair=pairs[i].split('=');if(keyPair.length==2)
{params[keyPair[0]]=unescape(keyPair[1]);}}
return params;},getScriptBySrc:function(srcUrl)
{var scripts=document.getElementsByTagName("script");for(var i=0;i<scripts.length;i++)
{var s=scripts[i];if(s.src.indexOf(srcUrl)!=-1)
{return s;}}
return null;},getWindowSize:function()
{var vW;var vH;if(typeof window.innerWidth!='undefined')
{vW=window.innerWidth,vH=window.innerHeight}
else if(typeof document.documentElement!='undefined'&&typeof document.documentElement.clientWidth!='undefined'&&document.documentElement.clientWidth!=0)
{vW=document.documentElement.clientWidth,vH=document.documentElement.clientHeight}
else
{vW=document.getElementsByTagName('body')[0].clientWidth,vH=document.getElementsByTagName('body')[0].clientHeight}
var rObj=[vW,vH];rObj.width=vW;rObj.height=vH;return rObj;},getPageScroll:function()
{var scrOfX=0,scrOfY=0;if(typeof(window.pageYOffset)=='number'){scrOfY=window.pageYOffset;scrOfX=window.pageXOffset;}else if(document.body&&(document.body.scrollLeft||document.body.scrollTop)){scrOfY=document.body.scrollTop;scrOfX=document.body.scrollLeft;}else if(document.documentElement&&(document.documentElement.scrollLeft||document.documentElement.scrollTop)){scrOfY=document.documentElement.scrollTop;scrOfX=document.documentElement.scrollLeft;}
return[scrOfX,scrOfY];},inArray:function(arr,val)
{if($iTXT.core.Util.isArray(arr))
{for(var i=0;i<arr.length;i++)
{if(this.fuzzyMatch(val,arr[i]))
{return true;}}}
return false;},objValues:function(obj)
{var rA=[];for(key in obj)
{if(obj[key]&&!this.isFunc(obj[key]))
{rA.push(obj[key]);}}
return rA;},objKeys:function(obj)
{var rA=[];for(key in obj)
{if(obj[key]&&!this.isFunc(obj[key]))
{rA.push(key);}}
return rA;},objCount:function(obj)
{return this.objValues(obj).length;},cacheImage:function(src)
{var im=new Image();im.src=src;},cacheImages:function(imgs)
{for(var i=0;i<imgs.length;i++)
{this.cacheImage(imgs[i]);}},serialise:function(object)
{return _iter(object,0);function _iter(obj,depth)
{var out='';if(!$iTXT.core.Util.isFunc(obj)&&!$iTXT.core.Util.isDOMNode(obj)&&($iTXT.core.Util.isObject(obj)||$iTXT.core.Util.isArray(obj)))
{var c=0;var k=[],nN=false;for(var n in obj)
{if(isNaN(n))
{nN=true;}
if(null!=obj[n]&&!$iTXT.core.Util.isFunc(obj[n]))
{k.push(n);}}
if(nN)
{k=k.sort();}
for(var i=0;i<k.length;i++)
{var elem=k[i];var pass='';var name='';if(!$iTXT.core.Util.isNumber(elem))
{name+=elem+':';}
if($iTXT.core.Util.isArray(obj[elem]))
{next=_iter(obj[elem],(depth+1));if(''!=next)
{pass+=name+'['+next+']';}}
else if($iTXT.core.Util.isObject(obj[elem]))
{next=_iter(obj[elem],(depth+1));if(''!=next)
{pass+=name+'{'+next+'}';}}
else if($iTXT.core.Util.isNumber(obj[elem]))
{pass+=name+obj[elem];}
else if($iTXT.core.Util.isString(obj[elem]))
{var delim=(obj[elem].match(/(^{|^[).*(]$|}$)/))?'':'"';pass+=name+delim+obj[elem].replace(/"/g,'\"')+delim;}
if(c>0&&''!=pass&&''!=out)
{pass=','+pass;}
c++;out+=pass;}
if(0==depth)
{out='{'+out+'}';}}
return out;}},matchObjs:function(o1,o2,precision)
{if(null==precision||undefined==precision||isNaN(precision))
{precision=0;}
if(this.isObject(o1)&&this.isObject(o2))
{var res=false;for(var fld in o1)
{if(!this.isFunc(o1[fld]))
{if(o2[fld])
{var sub=(this.isObject(o1[fld]))?this.matchObjs(o1[fld],o2[fld],precision):(this.fuzzyMatch(o1[fld],o2[fld]));if(!sub)
{return sub;}
else
{res=sub;}}
else if(precision>=0)
{return false;}}}
if(precision>0)
{for(var fld in o2)
{if(!this.isFunc(o2[fld]))
{if(o1[fld])
{var sub=(this.isObject(o2[fld]))?this.matchObjs(o2[fld],o1[fld],precision):(this.fuzzyMatch(o2[fld],o1[fld]));if(!sub)
{return sub;}
else
{res=sub;}}
else
{return false;}}}}
return res;}
return false;},fuzzyMatch:function(s1,s2)
{if(!this.isString(s1)||!this.isString(s2))
{return false;}
var m=new RegExp(((s1.match(/\*$/,''))?'^':'')+(s1.replace(/\*/g,''))+((s1.match(/^\*/,''))?'$':''));return(null!=s2.match(m));},reverseString:function(s)
{if(this.isString(s)||this.isNumber(s))
{s=s+'';s=s.split('');s=s.reverse();s=s.join('');}
return s;},sizeString:function(s,w,r,c)
{if((this.isString(s)||this.isNumber(s))&&this.isNumber(w)&&s.length!=w)
{if(r)
{s=this.reverseString(s);if(c&&this.isString(c))
{c=this.reverseString(c);}}
if(s.length>w)
{s=s.substr(0,w);}
else if(s.length<w)
{var p=w-s.length;for(var i=0;i<p;i++)
{if(!this.isString(c))
{c=' ';}
s+=c;}}
if(r)
{s=this.reverseString(s);}}
return s;},genUUID:function()
{return(s4()+s4()+"-"+s4()+"-4"+s4().substring(1,4)+"-"+sp()+"-"+s4()+s4()+s4());function s4()
{return(((1+Math.random())*0x10000)|0).toString(16).substring(1);}
function sp()
{var r4='';do
{r4=s4();}
while("8"!=r4.substring(0,1)&&"9"!=r4.substring(0,1)&&"a"!=r4.substring(0,1)&&"b"!=r4.substring(0,1));return r4;}},getNodeText:function(n)
{try
{if(n)
{return n.nodeValue;}}
catch(e)
{}
return"";},cloneArray:function(a)
{var ra=[];for(var i=0;i<a.length;i++)
{ra[i]=a[i];}
return ra;},cloneObject:function(src)
{var rO={};for(var p in src)
{if(undefined!=src[p])
{rO[p]=src[p];}}
return rO;},fixTags:function(s)
{var rxTag=new RegExp(/<([^>]+)\/?/gi);var rxAttr=new RegExp(/(\S+)=(["'])?((?:.(?!\2?\s+(?:\S+)=|(>|\2)))+.)\2?/gi);var tags;while(tags=rxTag.exec(s))
{var origTag=tags[0];var newTag=origTag;var attrs;while(attrs=rxAttr.exec(newTag))
{var origAttr=attrs[0];var quot=(this.isUndefined(attrs[2]))?'"':attrs[2];var newAttr=attrs[1]+'='+quot+attrs[3]+quot;if(origAttr!=newAttr)
{newTag=newTag.replace(origAttr,newAttr);}}
if(origTag!=newTag)
{s=s.replace(origTag,newTag);}}
return s;}};}
$iTXT.js.loader["$iTXT.core.Browser"]=true;$iTXT.core.Browser_Load=function(){var undefined;$iTXT.core.Browser={_browsers:[{s:navigator.userAgent,ss:"Chrome",id:"Chrome"},{s:navigator.userAgent,ss:"OmniWeb",vt:"OmniWeb/",id:"OmniWeb"},{s:navigator.vendor,ss:"Apple",id:"Safari",vt:"Version"},{prop:window.opera,id:"Opera"},{s:navigator.vendor,ss:"iCab",id:"iCab"},{s:navigator.vendor,ss:"KDE",id:"Konqueror"},{s:navigator.userAgent,ss:"Firefox",id:"Firefox"},{s:navigator.vendor,ss:"Camino",id:"Camino"},{s:navigator.userAgent,ss:"Netscape",id:"Netscape"},{s:navigator.userAgent,ss:"MSIE",id:"Explorer",vt:"MSIE"},{s:navigator.userAgent,ss:"Gecko",id:"Mozilla",vt:"rv"},{s:navigator.userAgent,ss:"Mozilla",id:"Netscape",vt:"Mozilla"}],useragent:"",version:0.0,performance:0,_versionTemplate:"",init:function()
{this.useragent=this._getUserAgent(this._browsers)||"Unknown User Agent";this.version=this._getVersion(navigator.userAgent)||this._getVersion(navigator.appVersion)||"Unkown Version";this.performance=this._performanceCheck();},_getUserAgent:function(d)
{for(var i=0;i<d.length;i++)
{var str=d[i].s;var prop=d[i].prop;this._versionTemplate=d[i].vt||d[i].id;if(str)
{if(str.indexOf(d[i].ss)!=-1)
return d[i].id;}
else if(prop)
{return d[i].id;}}},_getVersion:function(uas){var index=uas.indexOf(this._versionTemplate);return(index==-1)?undefined:parseFloat(uas.substring(index+this._versionTemplate.length+1));},is:function(ua,v,mode)
{var isVer=true;if(v)
{if(mode&&1==mode)
{isVer=(this.version>=v);}
else if(mode&&2==mode)
{isVer=(this.version<=v);}
else if(mode&&3==mode)
{isVer=(this.version>v);}
else if(mode&&4==mode)
{isVer=(this.version<v);}
else
{isVer=(v==this.version);}}
return(ua==this.useragent)&&isVer;},_performanceCheck:function()
{var rperf=50;if("Explorer"==this.useragent)
{if(this.version<6)
{rperf=50;}
else if(this.version<7)
{rperf=60;}
else if(this.version<8)
{rperf=80;}
else if(this.version<9)
{rperf=80;}}
else if("Firefox"==this.useragent)
{if(this.version<2)
{rperf=60;}
else if(this.version<3)
{rperf=70;}
else if(this.version<4)
{rperf=85;}
else if(this.version<5)
{rperf=95;}}
else if("Firefox"==this.useragent)
{if(this.version<2)
{rperf=60;}
else if(this.version<3)
{rperf=70;}
else if(this.version<4)
{rperf=90;}}
else if("Chrome"==this.useragent)
{if(this.version<2)
{rperf=70;}
else if(this.version<3)
{rperf=80;}
else if(this.version<4)
{rperf=98;}}
return rperf;}}
$iTXT.core.Browser.init();}
$iTXT.js.loader["$iTXT.core.Builder"]=true;$iTXT.core.Builder_Load=function(){var undefined;$iTXT.core.Builder={NODEMAP:{AREA:'map',CAPTION:'table',COL:'table',COLGROUP:'table',LEGEND:'fieldset',OPTGROUP:'select',OPTION:'select',PARAM:'object',TBODY:'table',TD:'table',TFOOT:'table',TH:'table',THEAD:'table',TR:'table'},make:function(tagName,attributes,children,doc)
{var documentContext=doc||document;var tagName=tagName.toUpperCase();var apngMode=false;var apngSrc="";if("APNG"==tagName)
{tagName="IMG";if(window.ActiveXObject)
{apngMode=true;apngSrc=attributes.src;attributes.src="px.gif";}}
var parentTagName=this.NODEMAP[tagName]||'div';var parentTag=document.createElement(parentTagName);try{parentTag.innerHTML="<"+tagName+"></"+tagName+">";}catch(e){}
var element=parentTag.firstChild||null;if(element&&(element.tagName.toUpperCase()!=tagName))
element=element.getElementsByTagName(tagName)[0];if(!element)element=documentContext.createElement(tagName);if(!element)return;if(attributes)
{var attrs=this._attributes(attributes);if(attrs.length){try{parentTag.innerHTML="<"+tagName+" "+attrs+"></"+tagName+">";}
catch(e){}
element=parentTag.firstChild||null;if(!element){element=documentContext.createElement(tagName);var classAdded=false;for(attr in attributes)
{element[attr]=attributes[attr];}}
if(element.tagName.toUpperCase()!=tagName)
element=parentTag.getElementsByTagName(tagName)[0];}}
if(children)
{this._children(element,children,documentContext);}
if(apngMode)
{element.style.filter="progid:DXImageTransform.Microsoft.AlphaImageLoader(src='"+apngSrc+"',sizingMethod='scale')";}
var rstClass="itxtrst"+tagName.toLowerCase();if(""!=element.className)
{element.className=rstClass+" "+element.className;}
else
{element.className=rstClass;}
return $iTXT.core.$(element);},_isSorN:function(param)
{return $iTXT.core.Util.isString(param)||$iTXT.core.Util.isNumber(param);},_children:function(element,children,documentContext)
{for(var i=0;i<children.length;i++)
{if(this._isSorN(children[i]))
{var span=document.createElement("SPAN");span.innerHTML=children[i];var i=0;while(span.firstChild)
{element.appendChild(span.firstChild);i++;if(i>10000)
{break;}}}
else
{element.appendChild(children[i]);}}},_attributes:function(attributes)
{var attrs=[];for(attribute in attributes)
{var an=(attribute=="className")?"class":attribute;attrs.push(an+'="'+attributes[attribute]+'"');}
return attrs.join(" ");}}}
$iTXT.js.loader["$iTXT.core.Class"]=true;$iTXT.core.Class_Load=function(){var undefined;$iTXT.core.Class={create:function()
{var parent=null;var properties=arguments[0];if($iTXT.core.Util.isFunc(properties))
{parent=properties;properties=arguments[1];}
function _newClass()
{this.init.apply(this,arguments);}
if(null!=parent)
{var parentClass=function(){};parentClass.prototype=parent.prototype
_newClass.prototype=new parentClass;}
for(p in properties)
{this._addProperty(_newClass,p,properties[p],parent);}
return _newClass;},_addProperty:function(_class,_property,_value,_parent)
{if($iTXT.core.Util.isFunc(_value)&&_parent&&undefined!=_parent.prototype[_property])
{var _oldValue=_value;_value=function()
{var _instance=this;var _newArgs=$iTXT.core.Util.args(arguments);var _super=function()
{return _parent.prototype[_property].apply(_instance,arguments);}
_newArgs.push(_super)
return _oldValue.apply(this,_newArgs);}}
_class.prototype[_property]=_value;}}}
$iTXT.js.loader["$iTXT.core.Dom"]=true;$iTXT.core.Dom_Load=function(){var undefined;$iTXT.core.$=function(elmt,dontExt)
{if($iTXT.core.Util.isString(elmt))
{elmt=document.getElementById(elmt);}
if(!elmt)
return null;if(dontExt||(elmt.itxt&&elmt.itxt.domExtended))
{return elmt;}
else
{elmt=$iTXT.core.Util.extend(elmt,$iTXT.core.Dom);elmt.itxt={};elmt.itxt.domExtended=true;return elmt;}}
$iTXT.core.Dom={iTXTEvents:{},itxtFire:function(type,data)
{$iTXT.core.Event.fire(this,type,data);return this;},itxtSubscribe:function(type,handler)
{$iTXT.core.Event.subscribe(this,type,handler);return this;},itxtUnSubscribe:function(type,handler)
{$iTXT.core.Event.unsubscribe(this,type,handler);return this;},itxtAddClass:function(addClass,removeClass)
{if(this.className)
{var cNs=this.className.split(' ');var newCNs=[];for(var i=0;i<cNs.length;i++)
{var cn=cNs[i];if(cn!=removeClass&&cn!=addClass)
{newCNs.push(cn);}}
newCNs.push(addClass);this.className=newCNs.join(' ');}
else
{this.className=addClass;}
return this;},itxtRemoveClass:function(removeClass)
{if(this.className)
{var cNs=this.className.split(' ');var newCNs=[];for(var i=0;i<cNs.length;i++)
{var cn=cNs[i];if(cn!=removeClass)
{newCNs.push(cn);}}
this.className=newCNs.join(' ');}
return this;},itxtSetStyle:function(styles,removeStyles)
{if(removeStyles)
{for(s in removeStyles)
{this.style[s]="";}}
if($iTXT.core.Util.isString(styles))
{return this.style.cssText+=";"+styles;}
for(s in styles)
{try
{if("cursor"==s&&"pointer"==styles[s])
{try
{this.style[s]="pointer";}
catch(se)
{this.style[s]="hand";}}
else
{this.style[s]=styles[s];}}
catch(e)
{$iTXT.core.$(document).itxtFire("$iTXT:console:log",{cat:"Exception",msg:("Exception: (itxtSetStyle(), dom.js:233,"+s+" = "+styles[s]+"):"+e)});}}
return this;},itxtSetAttribute:function(atts)
{for(attribute in atts)
{this[attribute]=atts[attribute];}
return this;},itxtHide:function()
{if(this.style.display!="none")
{this.itxt.display=this.style.display||"";this.style.display="none";}
return this;},itxtShow:function()
{this.style.display=this.itxt.display||"";return this;},ixtOpacity:function(o)
{if(window.ActiveXObject)
{this.style['filter']="alpha(opacity="+Math.round(100*o)+");";}
else
{this.style.mozOpacity=o;this.style.opacity=o;}
return this;},itxtAppendChildren:function(children)
{for(child in children)
{this.itxtAppendChild(children[child]);}
return this;},itxtAppendChild:function(child)
{if($iTXT.core.Util.isString(child))
{this.appendChild(document.createTextNode(child));}
else
{this.appendChild(child);}},itxtClear:function()
{while(this.firstChild)
{this.removeChild(this.firstChild);}},itxtTotalOffset:function()
{var element=this;var t=0;var l=0;do
{if((element==document.body)&&("relative"!=element.style.position))
{l+=element.offsetLeft;t+=element.offsetTop;}
else if(element!=document.body)
{l+=element.offsetLeft;t+=element.offsetTop;}
element=element.offsetParent;}
while(element)
var retArr=[l,t];retArr.left=l;retArr.top=t;return retArr;},itxtBounds:function()
{var nOff=this.itxtTotalOffset();var b={left:nOff.left,top:nOff.top,width:this.offsetWidth,height:this.offsetHeight};return b;}}}
$iTXT.js.loader["$iTXT.core.Event"]=true;$iTXT.core.Event_Load=function(){var undefined;$iTXT.core.Event={bind:function(source,func)
{return function()
{return func.apply(source,arguments);}},nsUID:0,subscribe:function(elmt,type,handler)
{elmt=$iTXT.core.$(elmt);var eventName=type;var eventUID=type;if(type.indexOf('.')!=-1)
{var splt=type.split('.');eventName=splt.pop();}
else
{eventUID="evt"+this.nsUID+++"."+eventName;}
var custom=eventName.charAt(0)=='$';if(custom)
{this._addEvt(elmt,eventName,eventUID,handler);}
else
{var intHandler=function(e)
{var newE=e||event;if(!newE.target&&newE.srcElement)
{newE.target=newE.srcElement;}
try
{if(3==newE.target.nodeType)
{newE.target=newE.target.parentNode;}}catch(exc){}
newE.stop=function()
{newE.cancelBubble=true;if(newE.stopPropagation)
{newE.stopPropagation();}}
var rv=handler.apply(elmt,[newE]);if(false===rv)
{if(e.preventDefault)
{e.preventDefault();}
e.returnValue=false;}
return rv;};if(elmt.addEventListener)
elmt.addEventListener(eventName,intHandler,false);else if(elmt.attachEvent)
elmt.attachEvent("on"+eventName,intHandler);}
this._addEvt(elmt,eventName,eventUID,handler,intHandler);},_addEvt:function(elmt,eventName,eventUID,handler,intHandler)
{var handlers=elmt.iTXTEvents[eventName]||{};handlers[eventUID]={handler:handler,intHandler:intHandler}
elmt.iTXTEvents[eventName]=handlers;},_removeEvt:function(elmt,eventName,eventUID,eventHandler)
{var handlers=elmt.iTXTEvents[eventName]||{};var newHandlers={};for(handler in handlers)
{if(handler!=eventUID&&handlers[handler].handler!=eventHandler)
{newHandlers[handler]=handlers[handler];}}
elmt.iTXTEvents[eventName]=newHandlers;},_getInternalHandler:function(elmt,eventName,eventUID,eventHandler)
{var handlers=elmt.iTXTEvents[eventName]||{};for(handler in handlers)
{if(handlers[handler].handler==eventHandler)
{return handlers[handler].intHandler;}}
return null;},unsubscribe:function(elmt,eventUID,handler)
{elmt=$iTXT.core.$(elmt);var eventName=eventUID;if(eventUID.indexOf('.')!=-1)
{var splt=eventUID.split('.');eventName=splt.pop();}
var custom=eventName.charAt(0)=='$';if(!custom)
{var intH=this._getInternalHandler(elmt,eventName,eventUID,handler);if(null!=intH)
{if(elmt.removeEventListener)
elmt.removeEventListener(eventName,intH,false);else if(elmt.detachEvent)
elmt.detachEvent("on"+eventName,intH);}}
this._removeEvt(elmt,eventName,eventUID,handler);},fire:function(elmt,eventName,data)
{elmt=$iTXT.core.$(elmt);var custom=eventName.charAt(0)=='$';var handlers=elmt.iTXTEvents[eventName]||{};var event={data:data||{}}
for(handler in handlers)
{if($iTXT.core.Util.isFunc(handlers[handler].handler))
{handlers[handler].handler.apply(elmt,[event]);}}
if(eventName&&"$iTXT:console:log"!=eventName)
{$iTXT.core.$(document).itxtFire("$iTXT:console:log",{cat:"Event",msg:eventName});}},preventDefault:function(e)
{if(e&&e.preventDefault)e.preventDefault();else if(window.event)window.event.returnValue=false;},stop:function(e)
{if(e&&e.stopPropagation)e.stopPropagation();else if(window.event)window.event.cancelBubble=true;}}}
$iTXT.js.loader["$iTXT.core.Math"]=true;$iTXT.core.Math_Load=function(){var undefined;$iTXT.core.Math={intersects:function(r1,r2)
{var l=(r1.left>r2.left)?r1.left:r2.left;var t=(r1.top>r2.top)?r1.top:r2.top;var r=((r1.left+r1.width)<(r2.left+r2.width))?(r1.left+r1.width):(r2.left+r2.width);var b=((r1.top+r1.height)<(r2.top+r2.height))?(r1.top+r1.height):(r2.top+r2.height);return(l<r&&t<b);},intersectsPercentage:function(r1,r2)
{var l=(r1.left>r2.left)?r1.left:r2.left;var t=(r1.top>r2.top)?r1.top:r2.top;var r=((r1.left+r1.width)<(r2.left+r2.width))?(r1.left+r1.width):(r2.left+r2.width);var b=((r1.top+r1.height)<(r2.top+r2.height))?(r1.top+r1.height):(r2.top+r2.height);if(l<r&&t<b)
{var w=r-l;var h=b-t;var area=w*h;var r1Area=r1.width*r1.height;return area/r1Area;}
return 0;},arrayMean:function(inA,abs)
{if(!$iTXT.core.Util.isArray(inA)||inA.length==0)
{return null;}
var tot=0,len=0;for(var i=0;i<inA.length;i++)
{if($iTXT.core.Util.isNumber(inA[i]))
{tot+=inA[i];len++;}}
var mean=tot/len;if(abs)
{return Math.abs(mean);}
else
{return mean;}},arrayMax:function(inA,abs)
{if(!$iTXT.core.Util.isArray(inA)||inA.length==0)
{return null;}
var max=0;for(var i=0;i<inA.length;i++)
{if($iTXT.core.Util.isNumber(inA[i]))
{if(0==max||inA[i]>max)
{max=inA[i];}}}
if(abs)
{return Math.abs(max);}
else
{return max;}},arrayMin:function(inA,abs)
{if(!$iTXT.core.Util.isArray(inA)||inA.length==0)
{return null;}
var min=0;for(var i=0;i<inA.length;i++)
{if($iTXT.core.Util.isNumber(inA[i]))
{if(0==min||inA[i]<min)
{min=inA[i];}}}
if(abs)
{return Math.abs(min);}
else
{return min;}}}}