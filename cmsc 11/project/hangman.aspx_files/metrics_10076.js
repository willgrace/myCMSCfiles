/* This source code is Copyright (c) Vibrant Media 2001-2010 and forms part of the patented Vibrant Media product "IntelliTXT" (sm). */ 
$iTXT.js.loader["$iTXT.metrics.Context"]=true;$iTXT.metrics.Context_Load=function(){var undefined;$iTXT.metrics.Context={nodeMetrics:{_lastInst:0,_lastInst:0,_intervals:[],_metrics:{},_events:{},_nodes:{},reset:function()
{this._lastInst=0;this._intervals=[];this._events={};this._metrics={};this._nodes={};},tick:function(mId,node)
{if(!$iTXT.core.Util.isString(mId))
{return;}
var inst=new Date().getTime();this._events[mId]=[];this._metrics[inst]=mId;var interval=inst-this._lastInst;if(this._lastInst>0&&interval>0)
{this._intervals.push(interval);}
this._lastInst=inst;if(node)
{if($iTXT.core.Util.isElement(node))
{node=$iTXT.core.Util.serialise($iTXT.data.Dom.parseElement(node,null));}
else if($iTXT.core.Util.isAttribute(node))
{node=node.nodeName+'@'+node.nodeValue;}
else if($iTXT.core.Util.isTextNode(node))
{node=$iTXT.core.Util.cleanString(node.nodeValue);if(""==node)
{node=null;}}
else
{node=null;}
if(node)
{this._nodes[mId]=node.substr(0,70);}}},tock:function(mId,evt)
{if(!$iTXT.core.Util.isString(mId)||!$iTXT.core.Util.isString(evt))
{return;}
var inst=new Date().getTime();var obj={};obj[evt]=inst;this._events[mId].push(obj);},dumpEvents:function()
{var count=0;var out="<tt>";for(var dt in this._metrics)
{var metric=this._metrics[dt];var title=this._nodes[metric]||metric;if(!$iTXT.core.Util.isFunc(metric))
{out+=$iTXT.core.Util.sizeString('',53,false,'-');out+=' ';out+=$iTXT.core.Util.sizeString('',14,false,'-');out+=' ';out+=$iTXT.core.Util.sizeString('',9,false,'-');out+='<br />'+(count++)+': '+title+'<br />';}
var evts=this._events[metric];var lastDT=0;for(var i=0;i<evts.length;i++)
{var thisEvt=evts[i];for(var eName in thisEvt)
{if(!$iTXT.core.Util.isFunc(thisEvt[eName]))
{var thisDT=thisEvt[eName];var dur=(lastDT==0)?0:thisDT-lastDT;out+=$iTXT.core.Util.sizeString(eName,53,false,'&nbsp;');out+=$iTXT.core.Util.sizeString(thisDT,15,true,'&nbsp;');out+=$iTXT.core.Util.sizeString(dur,10,true,'&nbsp;');out+='<br />';lastDT=thisDT;}}}}
out+=$iTXT.core.Util.sizeString('',53,false,'-');out+=' ';out+=$iTXT.core.Util.sizeString('',14,false,'-');out+=' ';out+=$iTXT.core.Util.sizeString('',9,false,'-');out+='</tt><br />';return out;},getMean:function(abs)
{return $iTXT.core.Math.arrayMean(this._intervals,abs);},getMax:function(abs)
{return $iTXT.core.Math.arrayMax(this._intervals,abs);},getMin:function(abs)
{return $iTXT.core.Math.arrayMin(this._intervals,abs);}}};}