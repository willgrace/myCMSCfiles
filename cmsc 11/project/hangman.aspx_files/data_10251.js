/* This source code is Copyright (c) Vibrant Media 2001-2010 and forms part of the patented Vibrant Media product "IntelliTXT" (sm). */ 
$iTXT.js.loader["$iTXT.data.AdLogger"]=true;$iTXT.data.AdLogger_Load=function(){var undefined;$iTXT.data.AdLogger=$iTXT.core.Class.create({server:"",qavTID:-1,trackingDrops:null,pWind:null,pWindName:"",pWindUrl:"",init:function(_opts)
{$iTXT.data.al=this;this.server=_opts.server||"mymachine";$iTXT.glob.serverURL=this.server;this.trackingDrops={};$iTXT.core.$(document).itxtSubscribe("$iTXT:data:adlog",$iTXT.core.Event.bind(this,this.log));$iTXT.core.$(document).itxtSubscribe("$iTXT:tt:open:prechromerw",$iTXT.core.Event.bind(this,this.ttOpen));$iTXT.core.$(document).itxtSubscribe("$iTXT:tt:close",$iTXT.core.Event.bind(this,this.ttClose));$iTXT.core.$(document).itxtSubscribe("$iTXT:tt:click",$iTXT.core.Event.bind(this,this._ttClick));$iTXT.core.$(document).itxtSubscribe("$iTXT:hk:click",$iTXT.core.Event.bind(this,this._hookClick));},log:function(e)
{this._log(e.data);},_log:function(opts)
{var url=this.buildAdLogUrl(opts);$iTXT.debug.Util.msg("Logging Advert Event: "+url);$iTXT.core.Util.dropScript(url,function(){document.body.removeChild(this);});},buildAdLogUrl:function(opts)
{var jsp=opts.jsp||"al.asp";var url='http://'+this.server+'/'+jsp+'?ts='+(new Date()).getTime();for(pn in opts)
{if(('undefined'!=typeof opts[pn])&&""!==opts[pn])
{url+="&"+pn+"="+encodeURIComponent(opts[pn]);}}
return url;},ttOpen:function()
{this._cancelQAVT();if(null!=$iTXT.tglb&&'undefined'!=typeof $iTXT.tglb&&'undefined'!=typeof $iTXT.tglb.getAVStub)
{return;}
var iTt=giTt();var ad=iTt.vm.a;var qavd=ad.params.get("qavd")||0;if(qavd>0)
{this.logAV(ad,7,false);var t=this;this.qavTID=window.setTimeout(function(){t.logAV(ad,1,true);},qavd);}
else
{this.logAV(ad,1,false);}},ttClose:function()
{this._cancelQAVT();},logAV:function(ad,avt,uqav)
{var opts={av:avt,ipid:ipid,di:ad.ldid,syid:ad.syid,adid:ad.adid,pid:ad.pid,cc:gGeo.cc,rcc:gGeo.rcc,so:(0==ad.at?9:iSo),mh:gSID,ll:ad.ll,hbll:ad.hbll,id:ad.id,pvu:gPVU,pvm:gPVM,uf:ad.uf,ur:ad.ur,idh:ad.idh}
if(ad.rc&&ad.rc.featured&&ad.rc.featured.wch)
{opts.wch=ad.rc.featured.wch;}
if(uqav)
{opts.uav=1;}
this._log(opts);if(1==avt&&!this.trackingDrops[ad.idh])
{this.trackingDrops[ad.idh]=1;var toks=itxtSubclass(gTokVals);var trkimages=ad.params.get("trkimages");if(trkimages&&$iTXT.core.Util.isArray(trkimages))
{for(var i=0;i<trkimages.length;i++)
{var cts=(new Date()).getTime().toString();toks.TIMESTAMP=cts;if(""!=trkimages[i])
{var imgSrc=trkimages[i];imgSrc=imgSrc.replace(/_TIMESTAMP_/g,cts);imgSrc=repToks(imgSrc,true,toks);$iTXT.func.dropBeacon(imgSrc,'img');}}}
if(ad.avs)
{itxtDSS(ad.avs);}}},_cancelQAVT:function()
{if(-1!=this.qavTID)
{window.clearTimeout(this.qavTID);this.qavTID=-1;}},buildClickUrl:function(a,clickOpts)
{var opts={};opts.ipid=clickOpts.ipid||ipid||'';opts.cc=clickOpts.cc||gGeo.cc||'';opts.rcc=clickOpts.rcc||gGeo.rcc||'';opts.qavclk=clickOpts.qavclk||undefined;if(a.ur)
{opts.ur=a.ur;opts.uf=a.uf;}
opts.di=a.ldid;opts.mh=clickOpts.sid||gSID||'';opts.syid=a.syid?a.syid:'';opts.adid=a.adid?a.adid:'';opts.pid=a.pid?a.pid:'';opts.id=a.id.length?a.id:'';opts.idh=a.idh.length?a.idh:'';opts.pvm=clickOpts.pvm||gPVM||'';opts.pvu=clickOpts.pvu||gPVU||'';opts.ll=a.ll;var dekw=encodeURIComponent(a.k);opts.ttv=clickOpts.ttv||0;opts.so=clickOpts.so||0;if(a.hbll)
{opts.hbll=a.hbll;}
opts.llip=clickOpts.llip||0;if(gKWPF)
{var anchor=aDIDN[a.did];var bb=cBB(anchor);if(bb!=null)
{clickOpts.kp=+bb.l+','+bb.t;}}
if(a.multi)
{if(!((13<opts.so)&&(20>opts.so)))
{clickOpts.redir=a.c;}
else
{var extraAds=a.adx.split('$$');var adDetail=extraAds[opts.so-14].split('||');clickOpts.redir=adDetail[3];}}
else if(a.c.length)
{var sSrchT=gSEST?decodeURIComponent(gSEST):"";var gSrchE_ID=gSEID?gSEID:0;if((sSrchT!=='')&&!(gSrchE_ID===0||gSrchE_ID===14)&&(a.at==32||a.at==34||a.at==46))
{var clk=gtADX(a.adx,"webClickURL2");clickOpts.redir=clk?clk:a.c;}
else
{clickOpts.redir=a.c;}}
opts.redir=clickOpts.redir||a.ct||"";opts.redir=$iTXT.func.appendToURL(opts.redir.replace(/_KEYWORD_/g,dekw).replace(/${KEYWORD}/g,dekw),(clickOpts.csp||''));if(clickOpts.vt)
{opts.vt=clickOpts.vt;}
var url=this.buildAdLogUrl(opts);return url;},_ttClick:function(e)
{if(!gSI&&!gIESI)
{$iTXT.debug.Util.msg('Return from kwC: !gSI 77 !gIESI');return false;}
var opts=e.data||{};e.data=opts;var a=fABDID(4==gPI?aADi:aAD,gDI);if(null==a)
{return false;}
var now=(new Date()).getTime();var tstto=(now-$iTXT.glob.ttopents);if(a&&a.params&&a.params.get("qavd")&&a.params.get("qavd")>0)
{if(tstto<a.params.get("qavd"))
{opts.qavclk=1;this._cancelQAVT();}
else
{opts.qavclk=2;}}
if(a.ct&&(now-a.ct<10000))
{$iTXT.debug.Util.msg('Return from kwC: Too soon (now '+now+' - a.ct '+a.ct+' < 10000)');return false;}
a.ct=now;var ttd=(gTTD>=1000?gTTD:750);if(opts.cm&&(opts.cm==2||opts.cm>1000))
{var minT=(opts.cm>=1000?opts.cm:ttd);if(tstto<minT)
{dbM('Clicked to early, click again in: '+(minT-tstto)+'ms');return false;}}
if(a.ll&&(true==a.ll)&&(!a.hbll||tstto<100))
{opts.llip=1;opts.rttclkt=('undefined'!=typeof opts.rttclkt)?(opts.rttclkt+250):0;if(opts.rttclkt<5000)
{var t=this;e.data.rttclkt=opts.rttclkt;$iTXT.debug.Util.msg('Retrying kwC: LL Too soon, retry in 250ms');window.setTimeout(function(){t._ttClick(e);},250);return false;}}
else
{opts.llip=0;}
if(a.ll&&a.hbll&&a.llcr&&a.at==4)
{$iTXT.debug.Util.msg('Return from kwC: Blocked',1);return false;}
opts.ttv=1;var url=this.buildClickUrl(a,opts);this._openUrl(url,a.cts);if(4!=gPI&&!a.cts)
{var cs=(10==opts.so)?3:((11<opts.so)?4:null);ttH(1,cs);}
return false;},_hookClick:function(e)
{},_openUrl:function(url,cts)
{if(cts)
{document.location=url;}
else
{var blocked=0;this.pWindUrl=url;this.pWindName='swnd_'+Math.floor(Math.random()*50);try
{this.pWind=window.open(url,this.pWindName,gWO);}
catch(e)
{blocked=1;}
if(this.pWind)
{window.setTimeout($iTXT.core.Event.bind(this,this._chkWindow),50);blocked=0;}
else
{blocked=1;}
if(blocked)
{if(null==$iTXT.glob.droppedBeacons)
{document.location=url;}
else
{$iTXT.func.checkBeacons(url);return false;}}}},_chkWindow:function()
{var blkd=0;var clsd=0;try
{clsd=this.pWind.closed;}
catch(e){}
if(!this.pWind||clsd||(gBVType=='opera'&&null==this.pWind.name))
{blkd=1;}
if(blkd)
{document.location=this.pWindUrl;}}});}
$iTXT.js.loader["$iTXT.data.Advert"]=true;$iTXT.data.Advert_Load=function(){var undefined;$iTXT.data.AdvertManager={id:0,ads:{},add:function(ad)
{if(ad)
{ad.id=this.id++;this.ads["itxtAdvert"+ad.id]=(ad);}},remove:function(advert)
{var newAds=[];for(adid in this.ads)
{var ad=this.ads[adid];if(ad!=advert)
{newAds["itxtAdvert"+ad.id]=ad;}}
this.ads=newAds;},get:function(id)
{return this.ads["itxtAdvert"+id]||null;},getByDid:function(did,caller)
{for(adid in this.ads)
{var ad=this.ads[adid];if(ad.$A&&ad.$A.did&&did==ad.$A.did&&ad!=caller)
{return ad;}}
return null;},list:function()
{var rArr=[];for(var i=1;i<this.id;i++)
{rArr.push(this.ads["itxtAdvert"+i]);}
return rArr;}}
$iTXT.data.Advert=$iTXT.core.Class.create({template:null,params:null,id:-1,did:0,liveLookupFinished:false,init:function(template,params,attributes)
{this.$A=attributes||{livelookup:false};this.did=this.$A.did;$iTXT.data.AdvertManager.add(this);this.template=template||$iTXT.tmpl.TemplateBase;this.params=params;},getTemplate:function()
{return eval(this.template);},addTemplateParams:function(params)
{if(this.params&&this.params.set)
{this.params.set(params,null,$iTXT.cnst.WEIGHTING_DEFAULT_TEMPLATE);}},tokenize:function(obj)
{return this.params.tokenize(obj);},liveLookup:function()
{if(this.$A.livelookup&&!this.liveLookupFinished)
{this.llBinding=$iTXT.core.Event.bind(this,this._liveLookupLoad);$iTXT.core.$(document).itxtSubscribe("$iTXT:livelookup:load:"+this.did,this.llBinding);var fo=0;var url='http:/'+'/'+$iTXT.glob.serverURL+'/v3/look.jsp?ipid='+$iTXT.glob.params.get("ipid")+'&did='+this.did+'&syid='+this.$A.syid+'&pid='+this.$A.pid+'&cc='+gGeo.cc+'&rcc='+gGeo.rcc+'&reg='+gGeo.reg+'&dma='+gGeo.dma+'&city='+encodeURIComponent(gGeo.city)+'&sid='+gSID+'&auat='+gAUAT+'&fo='+fo+'&pvu='+gPVU+'&pvm='+gPVM;var muid=gTc('MUID');if(''!=muid)
{url+='&muid='+muid;}
$iTXT.core.Util.dropScript(url);}},_liveLookupLoad:function(e)
{if(this.llBinding)
{$iTXT.core.$(document).itxtUnSubscribe("$iTXT:livelookup:load:"+this.did,this.llBinding)}
this.liveLookupFinished=true;if(e.data&&e.data.did)
{var newAd=$iTXT.data.AdvertManager.getByDid(e.data.did,this);if(null!=newAd)
{newAd.liveLookupFinished=true;if(this.hook)
{this.hook.setAdvert(newAd);}
$iTXT.core.$(document).itxtFire("$iTXT:livelookup:finished",newAd);$iTXT.data.AdvertManager.remove(this);}}}});}
$iTXT.js.loader["$iTXT.data.Context"]=true;$iTXT.data.Context_Load=function(){var undefined;$iTXT.data.Context={hCnt:0,pCnt:0,imageNodes:[],textNodes:[],timings:{},Node:$iTXT.core.Class.create({c:null,h:null,i:null,n:null,p:null,t:null,u:null,w:null,x:null,_node:null,init:function(node,params,parent)
{if(params.metrics&$iTXT.debug.Util.ECH_EVENTS_TIME)
{params.metricID=$iTXT.core.Util.genUUID();$iTXT.metrics.Context.nodeMetrics.tick(params.metricID,node);$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'init: start');}
this._node=node;if(this._checkLimits(params))
{this._node=null;return;}
var assessment={};assessment.isElement=$iTXT.core.Util.isElement(node);assessment.isAttribute=$iTXT.core.Util.isAttribute(node);assessment.isTextNode=$iTXT.core.Util.isTextNode(node);if(!$iTXT.core.Util.isDOMNode(node))
{if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'init: early end - unsuitable element');}
return;}
if(assessment.isTextNode)
{var nV=$iTXT.core.Util.cleanString(this._node.nodeValue);if(null==nV||$iTXT.core.Util.isUndefined(nV)||""==nV)
{if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'init: early end - unsuitable content');}
return;}}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'init: start assessment');}
if(params.assessor instanceof $iTXT.data.Dom.SelectorAssessor&&assessment.isElement)
{var thisA=node.itxtAssessed;if(!thisA||!$iTXT.core.Util.isObject(thisA))
{var sel=$iTXT.data.Dom.parseElement(this._node,params.intattrs);thisA=params.assessor.assess(sel);if(params.metrics&$iTXT.debug.Util.ECH_ASSESS_DUMP)
{var aStr='';for(var a in thisA)
{if(!$iTXT.core.Util.isFunc(thisA[a]))
{aStr+='&nbsp;&nbsp;&nbsp;&nbsp;'+a+': '+thisA[a]+'<br/>';}}
if(''!=aStr)
{$iTXT.debug.Util.msg('<b style="color:blue;">ECH:</b> Node "'+$iTXT.core.Util.serialise(sel)+'" assessed as:<br />'+aStr);}}}
for(var k in thisA)
{if(!$iTXT.core.Util.isFunc(thisA[k]))
{if($iTXT.core.Util.isArray(thisA[k])&&$iTXT.core.Util.isArray(assessment[k]))
{assessment[k]=assessment[k].concat(thisA[k]);}
else if(!$iTXT.core.Util.isUndefined(thisA[k]))
{assessment[k]=thisA[k];}}}}
if(assessment.isElement)
{try
{node.itxtAssessed=$iTXT.core.Util.serialise(assessment);}
catch(x)
{$iTXT.debug.Util.msg('<b style="color:blue;">ECH:</b> Could not attach assessment to node ('+node+') due to error "'+x.message+'".');}}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'init: end assessment');}
$iTXT.data.Context.incProcessedCount();this.i=$iTXT.data.Context.getProcessedCount();if(!params.processed)
{if($iTXT.core.Util.isUndefined(params.maxImageW))
{params.maxImageW=-1;}
if($iTXT.core.Util.isUndefined(params.maxImageH))
{params.maxImageH=-1;}
if($iTXT.core.Util.isUndefined(params.initskip))
{params.initskip=-1;}
if($iTXT.core.Util.isUndefined(params.maxnodedepth))
{params.maxnodedepth=-1;}
if($iTXT.core.Util.isUndefined(params.mintextlength))
{params.mintextlength=-1;}
if($iTXT.core.Util.isUndefined(params.maxheaderdepth))
{params.maxheaderdepth=3;}
if($iTXT.core.Util.isUndefined(params.timeout))
{params.timeout=3;}
if(params.initskip>0&&params.maxnodedepth>0)
{params.maxnodedepth+=params.initskip;}
params.processed=true;}
if(params.maxnodedepth<=0||this.i<=params.maxnodedepth)
{if(params.initskip<=0||this.i>=params.initskip)
{this._setType(params,assessment,parent);if(null!=this.t&&("bad"==this.t||$iTXT.core.Util.isUndefined(this.t)))
{if(assessment.isElement)
{try
{node.itxtProcessed=1;}
catch(x)
{$iTXT.debug.Util.msg('<b style="color:blue;">ECH:</b> Could not mark node ('+node+') as processed due to error "'+x.message+'".');}}
if("bad"==this.t)
{$iTXT.debug.Util.hilite(this._node,$iTXT.debug.Util.HL_COL_EXCLUDE);}
delete this.t;if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'init: early end - bad type');}
return;}
if(""==this.t)
{delete this.t;}
this._setHookable(params,assessment,parent);this._setParagraph(params,assessment,parent);this._setWeight(params,assessment,parent);this._setContent(params,assessment,parent);if(0==this.h)
{$iTXT.debug.Util.hilite(this._node,$iTXT.debug.Util.HL_COL_SKIP);}
else
{$iTXT.debug.Util.hilite(this._node,$iTXT.debug.Util.HL_COL_CONTENT);}}
else
{$iTXT.debug.Util.hilite(this._node,$iTXT.debug.Util.HL_COL_INIT);}
var me={h:this.h,p:this.p,t:this.t};if(parent&&parent.p&&1==parent.p)
{me.p=1;}
if(parent&&0==parent.h)
{me.h=0;}
this._setChildren(params,assessment,me);if(!this.c&&!this.u&&!this.w&&!this.x)
{delete this.p;delete this.h;delete this.t;delete this.i;}}
if(params.maxnodedepth>0&&this.i>params.maxnodedepth)
{delete this.i;}
if(assessment.isElement)
{try
{node.itxtProcessed=1;}
catch(x)
{$iTXT.debug.Util.msg('<b style="color:blue;">ECH:</b> Could not mark node ('+node+') as processed due to error "'+x.message+'".');}}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'init: end');}},serialise:function(all)
{if(all||this.c||this.u||this.w||this.x)
{return $iTXT.core.Util.serialise(this);}
else
{return'{}';}},_processNodes:function(nodeList,params,parent)
{if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_processNodes: start');}
var rA=[];for(var i=0;i<nodeList.length;i++)
{if(this._checkLimits(params))
{if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_processNodes: early end - _checkLimits');}
return rA;}
var node=new $iTXT.data.Context.Node(nodeList[i],params,parent)
var json=node.serialise();if('{}'!=json)
{rA.push(json);}
node=null;}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_processNodes: end');}
return rA;},_setChildren:function(params,assessment,parent)
{if(this._checkLimits(params))
{return;}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setChildren: start');}
if(assessment.isElement)
{var children=[];if(this._node.childNodes)
{children=children.concat(this._processNodes(this._node.childNodes,params,parent));}
if(params.intattrs&&this._node.attributes)
{var iAttrs=params.intattrs.split(",");var aNodes=[];for(var i=0;i<iAttrs.length;i++)
{aNodes.push(this._node.attributes[iAttrs[i]]);}
children=children.concat(this._processNodes(aNodes,params,parent));}
if(children.length>0)
{this.x=children;}}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setChildren: end');}},_setContent:function(params,assessment,parent)
{if(this._checkLimits(params))
{return;}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setContent: start');}
var content=null;var nName=this._node.nodeName;var nValue=$iTXT.core.Util.cleanString(this._node.nodeValue);if(assessment.isAttribute)
{content=nValue;}
else if(assessment.isTextNode)
{content=nValue;}
if(null!=content)
{if(content.length>1)
{content=content.replace(/"/g,'\\"');content=content.replace(/<.*>/g,"");if('url'==this.t||$iTXT.core.Util.isURL(content))
{this.u=content;}
else
{if((params.mintextlength>0)&&$iTXT.core.Util.isElement(this._node.parentNode)&&(1!=parent.p)&&("h"!=parent.t)&&("title"!=parent.t)&&("meta"!=parent.t)&&(content.length<params.mintextlength))
{if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setContent: early end - min-text length');}
return;}
if(content.length>0&&content.match(/[a-zA-Z0-9]/))
{var t=this.t||parent.t;var h=this.h||parent.h;if(null!=t&&'alt'==t)
{$iTXT.data.Context.imageNodes.push(this._node);this.n=$iTXT.data.Context.imageNodes.length;}
else if((null==h||$iTXT.core.Util.isUndefined(h)||h>0)&&null!=t&&'std'==t)
{$iTXT.data.Context.textNodes.push(this._node);this.n=$iTXT.data.Context.textNodes.length;}
$iTXT.data.Context.incHarvestedCount();this.c=content;if(null==this.t||$iTXT.core.Util.isUndefined(this.t)||""==this.t)
{this.t='std';}}}}}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setContent: end');}},_setHookable:function(params,assessment,parent)
{if(this._checkLimits(params))
{return;}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setHookable: start');}
if(assessment.isElement)
{if(null!=parent&&null==parent.h&&null!=this.t&&('a'==this.t||'alt'==this.t||'h'==this.t||'img'==this.t||'meta'==this.t||'title'==this.t||'url'==this.t))
{this.h=0;if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setHookable: early end - ex-officio not hookable type');}
return;}
if((assessment.isSkipnode||assessment.hasHooknodes)&&!assessment.isHooknode&&'std'==this.t)
{this.h=0;if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setHookable: early end - skip or not explicitly hookable');}
return;}}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setHookable: end');}},_setParagraph:function(params,assessment,parent)
{if(this._checkLimits(params))
{return;}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setParagraph: start');}
if(assessment.isSkipnode||(parent&&((parent.p&&1==parent.p)||(parent.t&&("title"==parent.t||"h"==parent.t))))||(this.t&&("title"==this.t||"h"==this.t)))
{this.p=null;if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setParagraph: early end - already in para or unsuitable type');}
return;}
var text=$iTXT.data.Dom.getInnerText(this._node,3);if(!params.mintextlength||!$iTXT.core.Util.isNumber(params.mintextlength))
{params.mintextlength=0;}
var lenOK=(null!=text&&text.length>=params.mintextlength);if(assessment.hasBreaknodes||assessment.hasUnbreaknodes)
{if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setParagraph: start related assessments');}
if(assessment.isElement)
{if(!assessment.isUnbreaknode&&!lenOK)
{this.p=null;if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setParagraph: early end - element node is UPN or has too little text');}}
if(null!=this._node.childNodes)
{for(var i=0;i<this._node.childNodes.length;i++)
{var cNode=this._node.childNodes[i];if($iTXT.core.Util.isElement(cNode))
{var cAssessment=cNode.itxtAssessed;if(!cAssessment||!$iTXT.core.Util.isObject(cAssessment))
{cAssessment=params.assessor.assess($iTXT.data.Dom.parseElement(cNode,params.intattrs),'breaknode');cAssessment.isElement=$iTXT.core.Util.isElement(cNode);cAssessment.isAttribute=$iTXT.core.Util.isAttribute(cNode);cAssessment.isTextNode=$iTXT.core.Util.isTextNode(cNode);if(cAssessment.isElement)
{try
{cNode.itxtAssessed=$iTXT.core.Util.serialise(cAssessment);}
catch(x)
{$iTXT.debug.Util.msg('<b style="color:blue;">ECH:</b> Could not attach assessment to node ('+cNode+') due to error "'+x.message+'".');}}}
if(cAssessment.isBreaknode)
{this.p=null;if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setParagraph: early end - child is BPN');}
return;}}}}
this.p=1;if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setParagraph: early end - is element paragraph');}
return;}
else if(assessment.isTextNode)
{if(lenOK)
{this.p=1;if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setParagraph: early end - is text node paragraph by length');}
return;}
else
{var cands=[];if(null!=this._node.parentNode&&$iTXT.core.Util.isElement(this._node.parentNode))
{cands.push(this._node.parentNode);}
if(null!=this._node.previousSibling&&$iTXT.core.Util.isElement(this._node.previousSibling))
{cands.push(this._node.previousSibling);}
if(null!=this._node.nextSibling&&$iTXT.core.Util.isElement(this._node.nextSibling))
{cands.push(this._node.nextSibling);}
for(var i=0;i<cands.length;i++)
{var spAssessment=cands[i].itxtAssessed;if(!spAssessment||!$iTXT.core.Util.isObject(spAssessment))
{spAssessment=params.assessor.assess($iTXT.data.Dom.parseElement(cands[i],params.intattrs),'breaknode');spAssessment.isElement=$iTXT.core.Util.isElement(cNode);spAssessment.isAttribute=$iTXT.core.Util.isAttribute(cNode);spAssessment.isTextNode=$iTXT.core.Util.isTextNode(cNode);if(spAssessment.isElement)
{try
{cands[i].itxtAssessed=$iTXT.core.Util.serialise(spAssessment);}
catch(x)
{$iTXT.debug.Util.msg('<b style="color:blue;">ECH:</b> Could not attach assessment to node ('+cands[i]+') due to error "'+x.message+'".');}}}
if(spAssessment.isBreaknode)
{this.p=1;if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setParagraph: early end - text node parent or sibling is BPN');}
return;}}}}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setParagraph: end related assessments');}}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setParagraph: end');}},_setType:function(params,assessment,parent)
{if(this._checkLimits(params))
{return;}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setType: start');}
if(assessment.isExcludenode)
{this.t='bad';if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setType: early end - exclude node');}
return;}
if($iTXT.core.Util.isURL(this._node.nodeValue))
{this.t='url';}
else if(assessment.isElement)
{switch(this._node.tagName.toLowerCase())
{case"img":var imgW=this._node.width;var imgH=this._node.height;if(params.minimagew>=0&&params.minimageh>=0&&(imgW<params.minimagew||imgH<params.minimageh))
{this.t="bad";if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setType: early end - bad image (too small)');}
return;}
var imgD="-"+imgW+"x"+imgH;switch(imgD)
{case"-120x600":case"-160x600":case"-300x250":case"-180x150":case"-728x90":this.t="bad";if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setType: early end - bad image (IAB)');}
return;break;}
break;case"title":case"meta":case"a":this.t=this._node.tagName.toLowerCase();break;case"h1":case"h2":case"h3":case"h4":case"h5":case"h6":var hLevel=this._node.tagName.toLowerCase().replace(/\D/,'');if(hLevel<=params.maxheaderdepth)
{this.t="h";}
else if(assessment.hasHooknodes&&!assessment.isHooknode)
{this.t="";}
else
{this.t="std";}
break;default:if(assessment.hasHooknodes&&!assessment.isHooknode)
{this.t="";}
else
{this.t="std";}
break;}}
else if(assessment.isAttribute)
{this.t=this._node.nodeName.toLowerCase();}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setType: end');}},_setWeight:function(params,assessment,parent)
{if(this._checkLimits(params))
{return;}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setWeight: start');}
if(assessment.weightset>0)
{this.w=assessment.weightset;delete assessment.weightset;}
if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_setWeight: end');}},_checkLimits:function(params)
{var tc=new Date().getTime();if(this._node&&this._node.itxtProcessed)
{if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_checkLimit: early end - loop detected');}
return true;}
else if(params.maxnodedepth>0&&$iTXT.data.Context.getHarvestedCount()>params.maxnodedepth)
{if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_checkLimit: early end - node count exceeded');}
return true;}
else if(params.timeout>0&&!$iTXT.core.Util.isUndefined($iTXT.data.Context.timings.cStart)&&(tc-$iTXT.data.Context.timings.cStart)>params.timeout)
{$iTXT.data.Context.timings.cEnd=tc;if(params.metricID)
{$iTXT.metrics.Context.nodeMetrics.tock(params.metricID,'_checkLimit: early end - timeout exceeded');}
return true;}
else
{return false;}}}),getHarvestedCount:function()
{return this.hCnt;},getProcessedCount:function()
{return this.pCnt;},incHarvestedCount:function()
{this.hCnt++;},incProcessedCount:function()
{this.pCnt++;},getContent:function()
{var oParams={};var sA=new $iTXT.data.Dom.SelectorAssessor();var pL=this.params.list(),params=[];for(var i=0;i<pL.length;i++)
{var pK=pL[i].toLowerCase();var pV=this.params.get(pK);if(null!=pV&&!$iTXT.core.Util.isUndefined(pV))
{if($iTXT.core.Util.isArray(pV)&&pV.length>0)
{var nodes=[],oths=[];if(pV[0].match(/:/))
{for(var j=0;j<pV.length;j++)
{var bits=pV[j].split(':');nodes.push(bits[0]);oths.push(bits[1]||1);}
pV=nodes;}
sA.add($iTXT.data.Dom.parseVMNode(pV),pK.replace(/s$/,''),oths);pV=null;}}
if(pK&&pV)
{oParams[pK]=pV;}}
if(sA.count()>0)
{oParams.assessor=sA;}
this.timings={};this.timings.cStart=new Date().getTime();if($iTXT.core.Util.isUndefined(oParams.startnode))
{oParams.startnode=document.getElementsByTagName('html')[0];}
if(oParams.metrics&$iTXT.debug.Util.ECH_ASSESS_DUMP)
{if(!$iTXT.metrics.Context)
{oParams.metrics=0;}
else
{$iTXT.metrics.Context.nodeMetrics.reset();}}
this.tree=new this.Node(oParams.startnode,oParams).serialise();var msgM='reached timeout of '+oParams.timeout+'ms';if($iTXT.core.Util.isUndefined(this.timings.cEnd))
{this.timings.cEnd=new Date().getTime();msgM='completed';}
$iTXT.debug.Util.msg('<b style="color:blue;">ECH:</b> Contextualisation '+msgM+' after '+(this.timings.cEnd-this.timings.cStart)+'ms, having processed '+this.getProcessedCount()+' nodes and harvested '+this.getHarvestedCount()+' nodes which produced a JSON string of '+(this.tree.length)+' bytes:<br/><span style="color:green;">'+this.tree+'</span>',1);if(oParams.metrics&$iTXT.debug.Util.ECH_EVENTS_TIME)
{$iTXT.debug.Util.msg('<b style="color:blue;">ECH:</b> Each node processed in an average of '+$iTXT.metrics.Context.nodeMetrics.getMean()+'ms with a minimum of '+$iTXT.metrics.Context.nodeMetrics.getMin()+'ms and a maximum of '+$iTXT.metrics.Context.nodeMetrics.getMax()+'ms.');if(oParams.metrics&$iTXT.debug.Util.ECH_EVENTS_DUMP)
{$iTXT.debug.Util.msg('<b style="color:blue;">ECH:</b> $iTXT.metrics.Context.nodeMetrics.dumpEvents():<br />'+$iTXT.metrics.Context.nodeMetrics.dumpEvents());}}}};}
$iTXT.js.loader["$iTXT.data.Country"]=true;$iTXT.data.Country_Load=function(){var undefined;$iTXT.data.Country={langs:{de:"de",at:"de",ch:"de",fr:"fr",gb:"en-gb",uk:"en-gb",it:"it",nl:"nl",se:"sv",no:"no",dk:"da",jp:"ja",cn:"zh",es:"es",fi:"fi",pl:"pl",ru:"ru",pt:"pt"},translations:{en:{sCC:"$",precs:"${SCC}",postcs:"",sspl:"Advertisement",swti:"What's this?",slm:"LEARN MORE",ssch:"Searching...",sbn:"Buy now",scls:"Close",sEet:"End time",sEcb:"Place bid",sEsn:"Seller",iert:"Articles related to <b>_KEYWORD_</b>",ierao:"Related Articles on ",iera:"Related Articles",wcfa:"Featured article",iist:"Shop for items related to ",iirt:"Search the web for info related to ",iimsnt:"Live Search for ",iivt:"Show video related to ",iiat:"Information related to ",gRCSrcTSt:"Search this site:",gRCSrc:"Search",gRCMor:"MORE",gROTE:"Roll over to expand",gCTLM:"Click to learn more"},"en-gb":{sCC:"&pound;"},fr:{sCC:"&euro;",sspl:"Publicit&#233;",swti:"Qu'est-ce que c'est?",sbn:"Achat maintenant",scls:"Fermer",sEet:"Temps restant",sEcb:"Ench&#233;rir",sEsn:"Vendeur",iert:"Liens similaires",ierao:"Articles connexes sur ",iera:"Articles connexes",wcfa:"Article phare",iist:"Boutique pour les produits apparent&#233;s &#224; ",iirt:"Rechercher sur le web une info apparent&#233;e &#224; ",iivt:"Visualiser les vid&#233;os apparent&#233;es &#224; ",iiat:"Information apparent&#233;e &#224; ",gRCSrcTSt:"Rechercher sur le site:",gRCSrc:"Rechercher",gRCMor:"PLUS",gROTE:"Agrandir la vid\u00E9o",gCTLM:"En savoir plus"},de:{sCC:"&euro;",sspl:"Werbung",swti:"was ist das?",sbn:"Jetzt kaufen",scls:"Schlie&#223;en",sEet:"Angebotsende",sEcb:"Bieten",sEsn:"Verk&#228;ufer",iert:"Weitere Links",ierao:"Themenverwandte Artikel ",iera:"Themenverwandte Artikel",wcfa:"Artikelhighlight",iist:"Finden Sie weitere Produkte zum Thema ",iirt:"Finden Sie weitere Informationen zum Thema ",iivt:"Videos zum Thema ",iiat:"Weitere Informationen zum Thema ",gRCSrcTSt:"Suche auf:",gRCSrc:"Suchen",gRCMor:"MEHR INFO",mlm:true,gROTE:"Hier Vergr\u00F6ssern",gCTLM:"Mehr Info"},es:{sCC:"&euro;",sspl:"Publicidad",swti:"&#191; Qu&#233; es esto?",scls:"cierre",iert:"Art&#237;culos Relacionados",ierao:"Otros art&#237;culos sobre ",iera:"Otros art&#237;culos",wcfa:"Art&#237;culo principal",iist:"Compra art&#237;culos relacionados con ",iirt:"B&#250;squeda para informaci&#243;n relacionado con ",iivt:"Mostrar video relacionado con ",iiat:"Informaci&#243;n relacionado con ",gRCSrcTSt:"B&#250;squeda del sitio:",gRCSrc:"Buscar",gRCMor:"M&#193;S",gROTE:"Pasar por encima",gCTLM:"Haz clic aqu\u00ED"},it:{sCC:"&euro;",sspl:"Pubblicit&#224;",swti:"Che cos'&#232;?",sbn:"Compra ora",scls:"Chiudi",sEet:"Ora di scadenza",sEcb:"Fai un'offerta",sEsn:"Venditore",iert:"Link similari",ierao:"Altri articoli su ",iera:"Altri articoli",wcfa:"In primo piano",iist:"Acquista prodotti in relazione a ",iirt:"Cerca nel web informazioni su ",iivt:"Mostra video su ",iiat:"Informazioni su ",gRCSrcTSt:"Cerca nel sito:",gRCSrc:"Cerca",gRCMor:"VAI",gROTE:"Passa il cursore qui sopra",gCTLM:"Clicca qui"},nl:{sCC:"&euro;",sspl:"Advertentie",swti:"Wat is dit?",scls:"Sluiten",sEet:"End time",iert:"Informatie in verband met <b>_KEYWORD_</b>",iist:"Shop voor een item in verband met ",iirt:"Zoek op het net voor informatie in verband met ",iivt:"Laat een video zien in verband met ",iiat:"Informatie in verband met ",gRCSrcTSt:"Zoeken op deze site:",gRCSrc:"Zoeken",gRCMor:"MEER",gROTE:"Wijs aan en vergroot",gCTLM:"Klik voor meer info"},sv:{sCC:"kr ",sspl:"Annons",swti:"Vad &#228;r detta?",sbn:"K&#246;pa nu",scls:"St&#228;nga",sEet:"Sluttid",sEcb:"L&#228;gg bud",sEsn:"s&#228;ljare",iert:"Relaterte l&#228;nkar",iist:"Handla varor relaterade till ",iirt:"S&#246;k p&#229; webben f&#246;r info relaterad till ",iivt:"Spela upp video relaterad till ",iiat:"Information relaterad till ",gRCSrcTSt:"S&#246;k p&#229; sidan:",gRCSrc:"S&#246;k",gRCMor:"MER",gROTE:"F\u00F6rstora med musen",gCTLM:"Klicka f\u00F6r mer info"},no:{sCC:"kr ",sspl:"Annonse",swti:"Hva er dette?",sbn:"Kj\u00D8p n\u00E5",scls:"Lukk vindu",sEet:"Sluttdato",sEcb:"Legg inn bud",sEsn:"Selger",iert:"Relaterte lenker",iist:"Shop etter relaterte produkter ",iirt:"S&#248;k p&#229; nettet for mer informasjon av ",iivt:"Se video p&#229; ",iiat:"Informasjon relatert til ",gRCSrcTSt:"S&#248;k p&#229; siden:",gRCSrc:"S&#248;ke",gRCMor:"MER",gROTE:"Mus over og utvid",gCTLM:"Klikk for \u00E5 se mer"},da:{sCC:"kr ",sspl:"Annonce",swti:"Hvad er dette?",sbn:"K\u00D8b nu",scls:"Luk vindue",sEet:"Slut",sEcb:"Byd",sEsn:"S\u00E6lger",iert:"Lignende links",iist:"Shop for ting relateret til ",iirt:"S&#248;g p&#229; nettet for ting relateret til ",iivt:"Vis video relateret til ",iiat:"Information relateret til ",gRCSrcTSt:"S&#248;g p&#229; siden:",gRCSrc:"S&#248;gning",gRCMor:"MERE",gROTE:"Rul over for st\u00F8rre",gCTLM:"Klik for mere viden"},fi:{sCC:"&euro;",sspl:"Mainos",swti:"Mik&#228; t&#228;m&#228; on?",ssch:"Etsim&#228;ss&#228;...",scls:"Sulje",gROTE:"Kohdista suurentaaksesi",gCTLM:"Klikkaa lis\u00E4tietoja"},ru:{sCC:"\u0440\u0443\u0431",sspl:"\u0420\u0435\u043A\u043B\u0430\u043C\u0430",swti:"\u0447\u0442\u043E \u044D\u0442\u043E?",slm:"\u0423\u0437\u043D\u0430\u0442\u044C \u043F\u043E\u0434\u0440\u043E\u0431\u043D\u0435\u0435",ssch:"\u041F\u043E\u0438\u0441\u043A...",sbn:"\u041A\u0443\u043F\u0438\u0442\u044C \u0421\u0435\u0439\u0447\u0430\u0441",scls:"\u0437\u0430\u043A\u0440\u044B\u0442\u044C (\u043E\u043A\u043D)",sEet:"\u0414\u043E \u043E\u043A\u043E\u043D\u0447\u0430\u043D\u0438\u044F",sEcb:"\u0421\u0434\u0435\u043B\u0430\u0442\u044C \u0441\u0442\u0430\u0432\u043A\u0443",sEsn:"\u041F\u0440\u043E\u0434\u0430\u0432\u0435\u0446",iert:"\u041F\u043E\u0445\u043E\u0436\u0438\u0435 \u0441\u0442\u0430\u0442\u044C\u0438",ierao:"\u041F\u043E\u0445\u043E\u0436\u0438\u0435 \u0441\u0442\u0430\u0442\u044C\u0438 ",iera:"\u041F\u043E\u0445\u043E\u0436\u0438\u0435 \u0441\u0442\u0430\u0442\u044C\u0438 ",wcfa:"\u041F\u043E\u0434\u043E\u0431\u0440\u0430\u043D\u043D\u0430\u044F \u0421\u0442\u0430\u0442\u044C\u044F",iist:"\u041A\u0443\u043F\u0438\u0442\u044C \u0442\u043E\u0432\u0430\u0440 \u0441\u0445\u043E\u0436\u0438\u0439 \u0441 ",iirt:"\u041F\u043E\u0438\u0441\u043A \u0432 \u0441\u0435\u0442\u0438 \u0438\u043D\u0444\u043E\u0440\u043C\u0430\u0446\u0438\u0438 \u043F\u043E ",iivt:"\u041F\u043E\u043A\u0430\u0437\u0430\u0442\u044C \u0432\u0438\u0434\u0435\u043E \u0441\u0445\u043E\u0436\u0435\u0435 \u0441 ",iiat:"\u0418\u043D\u0444\u043E\u0440\u043C\u0430\u0446\u0438\u044F \u043E\u0442\u043D\u043E\u0441\u044F\u0449\u0430\u044F\u0441\u044F \u043A ",gRCSrcTSt:"\u041F\u043E\u0438\u043A \u043F\u043E \u0441\u0430\u0439\u0442\u0443:",gRCSrc:"\u041F\u043E\u0438\u0441\u043A",gRCMor:"\u0414\u0410\u041B\u0415\u0415",gROTE:"&#1053;&#1072;&#1074;&#1077;&#1076;&#1080;&#32;&#1080;&#32;&#1091;&#1074;&#1077;&#1083;&#1080;&#1095;&#1100;",gCTLM:"&#1055;&#1086;&#1076;&#1088;&#1086;&#1073;&#1085;&#1086;"},pl:{sCC:"z\u0142",sspl:"Reklama",swti:"Co to jest?",slm:"DOWIEDZ SI\u0118 WI\u0118CEJ",ssch:"Trwa przeszukiwanie",sbn:"Kup teraz",scls:"Zamknij",sEet:"Koniec",sEcb:"Z\u0142\u00f3\u017c Ofert\u0119",sEsn:"Sprzedawca",iert:"Artyku\u0142y na podobny temat <b>_KEYWORD_</b>",iist:"Kupuj powi\u0105zane przedmioty ",iirt:"Szukaj w Internecie Informacji na podobny temat ",iivt:"Poka\u017c Video na podobny temat ",iiat:"Informacja na podobny temat ",gRCSrcTSt:"Szukaj na tej Stronie:",gRCSrc:"Szukaj",gRCMor:"Wi\u0119cej"},ja:{sCC:"&yen;",sspl:"\u30b9\u30dd\u30f3\u30b5\u30fc\u30ea\u30f3\u30af",swti:"\u3053\u306e\u5e83\u544a\u306b\u3064\u3044\u3066",sbn:"\u4eca\u8cb7\u7269",scls:"\u9589\u3058\u308b"},zh:{sCC:"&yen;",sspl:"\u5e7f\u544a",swti:"\u8fd9\u662f\u4ec0\u4e48\u5e7f\u544a",sbn:"\u4eca\u8cb7\u7269",scls:"\u5173\u5e7f\u544a"},pt:{gROTE:"Clique para aumentar",gCTLM:"Clique para mais info"}},country:"en",tr:function(name,cc)
{cc=cc||this.country;var lang=this.langs[cc]||"en";return this.translations[lang][name]||this.translations["en"][name]||"";},init:function(l)
{this.country=l;for(var prop in this.translations.en)
{window[prop]=this.tr(prop);$iTXT.glob.dbParams.set(prop,this.tr(prop),$iTXT.cnst.WEIGHTING_DEFAULT_DATABASE);}
$iTXT.glob.translationSet={};$iTXT.glob.translationSet.isMLM=(""==this.tr("mlm"))?false:this.tr("mlm");}};}
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
$iTXT.js.loader["$iTXT.data.Dom"]=true;$iTXT.data.Dom_Load=function(){var undefined;$iTXT.data.Dom={Selector:$iTXT.core.Class.create({init:function(tag,id,className,attrs)
{if(null!=tag&&$iTXT.core.Util.isString(tag)&&""!=tag)
{this.tag=tag.toLowerCase();}
if(null!=id&&$iTXT.core.Util.isString(id)&&""!=id)
{this.id=id.toLowerCase();}
if(null!=className&&$iTXT.core.Util.isString(className)&&""!=className)
{this.className=className.toLowerCase();}
if(null!=attrs&&$iTXT.core.Util.isObject(attrs)&&$iTXT.core.Util.objCount(attrs)>0)
{this.attrs={};for(var attr in attrs)
{if($iTXT.core.Util.isString(attrs[attr])||$iTXT.core.Util.isNumber(attrs[attr]))
{this.attrs[attr.toLowerCase()]=attrs[attr].toLowerCase();}}}}}),SelectorAssessor:$iTXT.core.Class.create({_othHash:{},_tagHash:{},_idHash:{},_classHash:{},_attrHash:{},_intHash:{},_count:0,_addToHash:function(h,i,k,v,hn)
{var xI={};if(!$iTXT.core.Util.isUndefined(h[i]))
{xI=h[i];}
var xV=[];if(!$iTXT.core.Util.isUndefined(xI[k]))
{xV=xI[k];}
if(!$iTXT.core.Util.isArray(xV)||$iTXT.core.Util.inArray(xV,v))
{return;}
xV.push(v);xI[k]=xV;if(k.match&&k.match(/\*/))
{xI.wild=true;}
h[i]=xI;},_extract:function(rO,i,h,s,f)
{if($iTXT.core.Util.isObject(rO)&&$iTXT.core.Util.isObject(i)&&$iTXT.core.Util.isObject(h)&&$iTXT.core.Util.isObject(s)&&$iTXT.core.Util.isString(f)&&!$iTXT.core.Util.isUndefined(s[f]))
{for(var int in i)
{if(i[int]&&!$iTXT.core.Util.isFunc(i[int]))
{if(h[int]&&$iTXT.core.Util.isObject(h[int]))
{var tO=h[int];var comps=[];if($iTXT.core.Util.isObject(s[f]))
{for(var oK in s[f])
{if(!$iTXT.core.Util.isFunc(s[f][oK]))
{comps.push=s[f][oK];}}}
else
{comps.push(s[f]);}
var cands=[];for(var j=0;j<comps.length;j++)
{var comp=comps[j];if(tO[comp])
{cands=cands.concat(tO[comp]);}
else if(tO.wild)
{for(var o in tO)
{if($iTXT.core.Util.isArray(tO[o]))
{cands=cands.concat(tO[o]);}}}}
if(cands.length>0&&$iTXT.data.Dom.findSelector(s,cands))
{var kN='is'+int.substr(0,1).toUpperCase()+int.substr(1);rO[kN]=true;var sz=$iTXT.core.Util.serialise(s);if(this._othHash[int]&&this._othHash[int][sz]&&$iTXT.core.Util.isArray(this._othHash[int][sz]))
{rO[int]=this._othHash[int][sz][0];}
delete i[int];}}}}}
return rO;},add:function(sel,int,oth)
{if((!$iTXT.core.Util.isObject(sel)&&!$iTXT.core.Util.isArray(sel))||!$iTXT.core.Util.isString(int))
{return;}
var sA=[];var oA=[];if(!$iTXT.core.Util.isArray(sel))
{sA[0]=sel;}
else
{sA=sel;}
if(!$iTXT.core.Util.isArray(oth))
{oA[0]=oth;}
else
{oA=oth;}
if(!$iTXT.core.Util.isObject(sel[0]))
{return;}
for(var i=0;i<sA.length;i++)
{sel=sA[i];oth=oA[i];if($iTXT.core.Util.isUndefined(sel.tag)&&$iTXT.core.Util.isUndefined(sel.id)&&$iTXT.core.Util.isUndefined(sel.className)&&$iTXT.core.Util.isUndefined(sel.attrs))
{continue;}
var s=$iTXT.core.Util.serialise(sel);this._intHash[int]=true;if(!$iTXT.core.Util.isUndefined(sel.tag))
{this._addToHash(this._tagHash,int,sel.tag,sel,'tagHash');}
if(!$iTXT.core.Util.isUndefined(sel.id))
{this._addToHash(this._idHash,int,sel.id,sel,'idHash');}
if(!$iTXT.core.Util.isUndefined(sel.className))
{this._addToHash(this._classHash,int,sel.className,sel,'classHash');}
if($iTXT.core.Util.isObject(sel.attrs))
{for(var aN in sel.attrs)
{if(!$iTXT.core.Util.isFunc(sel.attrs[aN]))
{this._addToHash(this._attrHash,int,aN,sel,'attrHash');}}}
if(!$iTXT.core.Util.isUndefined(oth))
{this._addToHash(this._othHash,int,s,oth,'othHash');}
this._count++;}},assess:function(sel,spInt)
{if(!sel instanceof $iTXT.data.Dom.Selector)
{return{};}
var intHash={};if(spInt&&$iTXT.core.Util.isString(spInt))
{intHash[spInt]=true;}
else
{for(var k in this._intHash)
{if(!$iTXT.core.Util.isFunc(this._intHash))
{intHash[k]=this._intHash[k];}}}
var s=$iTXT.core.Util.serialise(sel);var rO={};for(var int in intHash)
{if(!$iTXT.core.Util.isFunc(int))
{rO['has'+int.substr(0,1).toUpperCase()+int.substr(1)+'s']=true;rO['is'+int.substr(0,1).toUpperCase()+int.substr(1)]=false;}}
rO=this._extract(rO,intHash,this._tagHash,sel,'tag');rO=this._extract(rO,intHash,this._idHash,sel,'id');rO=this._extract(rO,intHash,this._classHash,sel,'className');rO=this._extract(rO,intHash,this._attrHash,sel,'attrs');return rO;},count:function()
{return this._count;},init:function()
{}}),parseSelector:function(selector,vmmode)
{var tag='',separator='',identifier='',value='',out=null;var PATTERN1=(vmmode)?/(\>\@|\>|\!|\@)/:/(\#|\.)/;var PATTERN2=/\=/;if(selector.match(PATTERN1))
{separator=selector.match(PATTERN1)[0];var bits=selector.split(separator,2);if(vmmode)
{separator=separator.replace(/\>\@/,'@').replace(/\>/,'#').replace(/\!/,'.')}
tag=bits[0];identifier=bits[1];if(vmmode&&identifier.match(PATTERN2))
{var vsep=identifier.match(PATTERN2)[0];var vbits=identifier.split(vsep,2);identifier=vbits[0];value=vbits[1];}}
else
{tag=selector;}
if(vmmode)
{var id=null,className=null,attr=null,val=null;if(selector==tag)
{separator='#';identifier=selector;tag='';}
if(''!=tag)
{tag=tag.toLowerCase().replace(/\<|\>/,'')}
if(''!=identifier)
{switch(separator)
{case"#":id=identifier;break;case".":className=identifier;break;case"@":attr=identifier;if(''!=value)
{val=value;}
else
{val='*';}
break;}}
var attrO={};if(attr)
{attrO[attr]=val;}
out=new $iTXT.data.Dom.Selector(tag,id,className,attrO);}
else
{out=[tag.toLowerCase(),separator,identifier];}
return out;},findSelector:function(needle,haystack,precision)
{function _checkField(n,h,p)
{if($iTXT.core.Util.isUndefined(n)||$iTXT.core.Util.isUndefined(h))
{return(p==0)?true:false;}
else
{return $iTXT.core.Util.fuzzyMatch(h,n);}}
if(!precision||!$iTXT.core.Util.isNumber(precision))
{precision=0;}
var nA=[];if(!$iTXT.core.Util.isArray(needle))
{nA.push(needle);}
else
{nA=needle;}
var hA=[];if(!$iTXT.core.Util.isArray(haystack))
{hA.push(haystack);}
else
{hA=haystack;}
for(var i=0;i<nA.length;i++)
{for(var j=0;j<hA.length;j++)
{var ret=false;var tN=nA[i];var tH=hA[j];if(precision<0)
{ret=(_checkField(tN.tag,tH.tag,precision)||_checkField(tN.id,tH.id,precision)||_checkField(tN.className,tH.className,precision)||_checkField(tN.attr,tH.attr,precision)||_checkField(tN.val,tH.val,precision))}
else
{ret=(_checkField(tN.tag,tH.tag,precision)&&_checkField(tN.id,tH.id,precision)&&_checkField(tN.className,tH.className,precision)&&_checkField(tN.attr,tH.attr,precision)&&_checkField(tN.val,tH.val,precision))}
if(ret)
{return ret;}}}
return false;},extractAttrs:function(elem,constraint)
{var out={};if($iTXT.core.Util.isElement(elem)&&elem.attributes)
{for(var i=0;i<elem.attributes.length;i++)
{var attr=elem.attributes[i];if(constraint&&$iTXT.core.Util.isObject(constraint))
{if($iTXT.core.Util.isUndefined(constraint[attr.nodeName]))
{continue;}}
if("id"!=attr.nodeName&&"class"!=attr.nodeName)
{out[attr.nodeName]=attr.nodeValue;}}}
return out;},parseVMNode:function(inp)
{var outA=[];if(null!=inp)
{if(!$iTXT.core.Util.isArray(inp))
{inp=[inp];}
for(var i=0;i<inp.length;i++)
{var sel=this.parseSelector(inp[i],true);if(sel instanceof $iTXT.data.Dom.Selector)
{outA.push(sel);}}}
if(outA.length==1)
{return outA[0];}
else
{return outA;}},parseElement:function(inp,attrC)
{var inA=[],outA=[];if($iTXT.core.Util.isElement(inp))
{inA.push(inp);}
else if($iTXT.core.Util.isUndefined(inp))
{return null;}
else
{inA=inp;}
for(var i=0;i<inA.length;i++)
{var elem=inA[i];if($iTXT.core.Util.isElement(elem))
{if(outA.length==0)
{var attrO=null;if(attrC&&$iTXT.core.Util.isString(attrC))
{attrO={};attrC=attrC.split(",");for(var i=0;i<attrC.length;i++)
{attrO[attrC[i]]=true;}
attrO=this.extractAttrs(elem,attrO);}
outA.push(new $iTXT.data.Dom.Selector(elem.tagName.toLowerCase(),elem.id,elem.className,attrO));}}}
if(outA.length==1)
{return outA[0];}
else
{return outA;}},getInnerText:function(node,maxD,currD)
{if(null==maxD||$iTXT.core.Util.isUndefined(maxD)||!$iTXT.core.Util.isNumber(maxD))
{maxD=-1;}
if(null==currD||$iTXT.core.Util.isUndefined(currD)||!$iTXT.core.Util.isNumber(currD))
{currD=0;}
currD++;if(!node.itxtIT&&(maxD<0||maxD>=currD))
{if(maxD<0)
{try
{node.itxtIT=1;}
catch(x)
{}}
if($iTXT.core.Util.isTextNode(node))
{return $iTXT.core.Util.cleanString(node.nodeValue);}
else if($iTXT.core.Util.isElement(node))
{var out='',children=node.childNodes;for(var i=0;i<children.length;i++)
{out+=' '+this.getInnerText(children[i],maxD,currD);}
return $iTXT.core.Util.cleanString(out);}}
return'';}}}
$iTXT.js.loader["$iTXT.data.Param"]=true;$iTXT.data.Param_Load=function(){var undefined;$iTXT.data.Param=$iTXT.core.Class.create({paramHash:null,parent:null,init:function(p,params,weight)
{this.matchRegEx=new RegExp("\\$\\{[^}]*\\}","gi");this.paramHash={}
this.parent=p||null;if(params&&weight)
{this.set(params,null,weight);}},list:function()
{return $iTXT.core.Util.objKeys(this.paramHash);},get:function(pname,defVal)
{var retVal=defVal||null;var pV=null,pW=0,mV=null,mW=0;if(null!=this.paramHash[pname.toUpperCase()])
{mW=this.paramHash[pname.toUpperCase()].w;mV=this.paramHash[pname.toUpperCase()].v;}
if(this.parent!=null&&this.parent.get)
{pW=this.parent.weigh(pname.toUpperCase());pV=this.parent.get(pname.toUpperCase(),defVal);}
if(null!=pV&&null==mV)
{retVal=pV;}
else if(null!=mV&&null==pV)
{retVal=mV;}
else if(null!=mV&&null!=pV)
{if(pW>mW)
{retVal=pV;}
else
{retVal=mV;}}
return retVal;},weigh:function(pname)
{var retVal=0,pW=0,mW=0;if(null!=this.paramHash[pname])
{mW=this.paramHash[pname].w;}
if(null!=this.parent&&this.parent.weigh)
{pW=this.parent.weigh(pname);}
if(pW>mW)
{retVal=pW;}
else
{retVal=mW;}
return retVal;},set:function(arg1,arg2,arg3)
{if($iTXT.core.Util.isString(arg1))
{this.paramHash[arg1.toUpperCase()]=this._qualify(arg1,arg2,arg3);}
else if($iTXT.core.Util.isObject(arg1))
{for(var nm in arg1)
{this.paramHash[nm.toUpperCase()]=this._qualify(nm,arg1[nm],arg3);}}},unset:function(pname)
{delete this.paramHash[pname.toUpperCase()];},exists:function(pname)
{var pT=false;if(this.parent!=null&&this.parent.exists)
{pT=this.parent.exists(pname);}
var mT=(this.paramHash[pname.toUpperCase()]!=null);return pT||mT;},parse:function(s,obj,lvl)
{lvl=lvl||1;var components=s.match(this.matchRegEx);if(components)
for(var i=0;i<components.length;i++)
{var comp=components[i];var varname=comp.substring(2,comp.length-1).toUpperCase();if(obj&&obj[varname])
{s=s.replace(comp,obj[varname]);}
else if(this.exists(varname))
{s=s.replace(comp,this.get(varname));}}
if(lvl<3)
{lvl+=1;s=this._expand(s,obj,lvl);}
return s;},_param:function(pname,val,weight)
{var r={n:pname.toUpperCase(),v:val,w:(weight||0)}
return r;},_qualify:function(pname,val,weight)
{if($iTXT.core.Util.isObject(val)&&undefined!=val.v&&undefined!=val.w)
{weight=val.w;val=val.v;}
if(null!=this.paramHash[pname.toUpperCase()])
{var curV=this.paramHash[pname.toUpperCase()];var newV=this._param(pname.toUpperCase(),val,weight);return(newV.w>=curV.w)?newV:curV;}
else
{return this._param(pname.toUpperCase(),val,weight);}},_expand:function(val,obj,lvl)
{if(val&&$iTXT.core.Util.isString(val)&&val.match(/\$\{/))
{val=this.parse(val,obj,lvl);}
return val;},getParamList:function(childParams)
{var returnParams=childParams||{};for(var p in this.paramHash)
{if(!returnParams[p])
{returnParams[p]=this.get(p);}}
if(this.parent)
{return this.parent.getParamList(returnParams);}
return returnParams;},tokenize:function(obj)
{if($iTXT.core.Util.isString(obj))
{obj=this.parse(obj);}
else if($iTXT.core.Util.isObject(obj))
{for(p in obj)
{obj[p]=this.tokenize(obj[p]);}}
return obj;}});}