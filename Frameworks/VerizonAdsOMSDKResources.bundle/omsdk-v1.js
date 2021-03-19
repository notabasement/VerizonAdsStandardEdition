;(function(omidGlobal) {
  'use strict';var n;function aa(a){var b=0;return function(){return b<a.length?{done:!1,value:a[b++]}:{done:!0}}}function p(a){var b='undefined'!=typeof Symbol&&Symbol.iterator&&a[Symbol.iterator];return b?b.call(a):{next:aa(a)}}function q(a){if(!(a instanceof Array)){a=p(a);for(var b,c=[];!(b=a.next()).done;)c.push(b.value);a=c}return a}var ba='function'==typeof Object.create?Object.create:function(a){function b(){}b.prototype=a;return new b},ca;
if('function'==typeof Object.setPrototypeOf)ca=Object.setPrototypeOf;else{var da;a:{var ea={R:!0},fa={};try{fa.__proto__=ea;da=fa.R;break a}catch(a){}da=!1}ca=da?function(a,b){a.__proto__=b;if(a.__proto__!==b)throw new TypeError(a+' is not extensible');return a}:null}var ha=ca;
function r(a,b){a.prototype=ba(b.prototype);a.prototype.constructor=a;if(ha)ha(a,b);else for(var c in b)if('prototype'!=c)if(Object.defineProperties){var d=Object.getOwnPropertyDescriptor(b,c);d&&Object.defineProperty(a,c,d)}else a[c]=b[c];a.Ba=b.prototype}var t='undefined'!=typeof window&&window===this?this:'undefined'!=typeof global&&null!=global?global:this;function u(a,b){return Object.prototype.hasOwnProperty.call(a,b)}
var ia='function'==typeof Object.assign?Object.assign:function(a,b){for(var c=1;c<arguments.length;c++){var d=arguments[c];if(d)for(var e in d)u(d,e)&&(a[e]=d[e])}return a},v='function'==typeof Object.defineProperties?Object.defineProperty:function(a,b,c){a!=Array.prototype&&a!=Object.prototype&&(a[b]=c.value)};
function w(a,b){if(b){var c=t;a=a.split('.');for(var d=0;d<a.length-1;d++){var e=a[d];e in c||(c[e]={});c=c[e]}a=a[a.length-1];d=c[a];b=b(d);b!=d&&null!=b&&v(c,a,{configurable:!0,writable:!0,value:b})}}w('Object.assign',function(a){return a||ia});function ja(){ja=function(){};t.Symbol||(t.Symbol=ka)}function la(a,b){this.a=a;v(this,'description',{configurable:!0,writable:!0,value:b})}la.prototype.toString=function(){return this.a};
var ka=function(){function a(c){if(this instanceof a)throw new TypeError('Symbol is not a constructor');return new la('jscomp_symbol_'+(c||'')+'_'+b++,c)}var b=0;return a}();function x(){ja();var a=t.Symbol.iterator;a||(a=t.Symbol.iterator=t.Symbol('Symbol.iterator'));'function'!=typeof Array.prototype[a]&&v(Array.prototype,a,{configurable:!0,writable:!0,value:function(){return ma(aa(this))}});x=function(){}}function ma(a){x();a={next:a};a[t.Symbol.iterator]=function(){return this};return a}
w('WeakMap',function(a){function b(f){this.a=(l+=Math.random()+1).toString();if(f){f=p(f);for(var h;!(h=f.next()).done;)h=h.value,this.set(h[0],h[1])}}function c(){}function d(f){if(!u(f,g)){var h=new c;v(f,g,{value:h})}}function e(f){var h=Object[f];h&&(Object[f]=function(k){if(k instanceof c)return k;d(k);return h(k)})}if(function(){if(!a||!Object.seal)return!1;try{var f=Object.seal({}),h=Object.seal({}),k=new a([[f,2],[h,3]]);if(2!=k.get(f)||3!=k.get(h))return!1;k.delete(f);k.set(h,4);return!k.has(f)&&
4==k.get(h)}catch(m){return!1}}())return a;var g='$jscomp_hidden_'+Math.random();e('freeze');e('preventExtensions');e('seal');var l=0;b.prototype.set=function(f,h){d(f);if(!u(f,g))throw Error('WeakMap key fail: '+f);f[g][this.a]=h;return this};b.prototype.get=function(f){return u(f,g)?f[g][this.a]:void 0};b.prototype.has=function(f){return u(f,g)&&u(f[g],this.a)};b.prototype.delete=function(f){return u(f,g)&&u(f[g],this.a)?delete f[g][this.a]:!1};return b});
w('Map',function(a){function b(){var f={};return f.A=f.next=f.head=f}function c(f,h){var k=f.a;return ma(function(){if(k){for(;k.head!=f.a;)k=k.A;for(;k.next!=k.head;)return k=k.next,{done:!1,value:h(k)};k=null}return{done:!0,value:void 0}})}function d(f,h){var k=h&&typeof h;'object'==k||'function'==k?g.has(h)?k=g.get(h):(k=''+ ++l,g.set(h,k)):k='p_'+h;var m=f.b[k];if(m&&u(f.b,k))for(f=0;f<m.length;f++){var z=m[f];if(h!==h&&z.key!==z.key||h===z.key)return{id:k,list:m,index:f,o:z}}return{id:k,list:m,
index:-1,o:void 0}}function e(f){this.b={};this.a=b();this.size=0;if(f){f=p(f);for(var h;!(h=f.next()).done;)h=h.value,this.set(h[0],h[1])}}if(function(){if(!a||'function'!=typeof a||!a.prototype.entries||'function'!=typeof Object.seal)return!1;try{var f=Object.seal({x:4}),h=new a(p([[f,'s']]));if('s'!=h.get(f)||1!=h.size||h.get({x:4})||h.set({x:4},'t')!=h||2!=h.size)return!1;var k=h.entries(),m=k.next();if(m.done||m.value[0]!=f||'s'!=m.value[1])return!1;m=k.next();return m.done||4!=m.value[0].x||
't'!=m.value[1]||!k.next().done?!1:!0}catch(z){return!1}}())return a;x();var g=new WeakMap;e.prototype.set=function(f,h){f=0===f?0:f;var k=d(this,f);k.list||(k.list=this.b[k.id]=[]);k.o?k.o.value=h:(k.o={next:this.a,A:this.a.A,head:this.a,key:f,value:h},k.list.push(k.o),this.a.A.next=k.o,this.a.A=k.o,this.size++);return this};e.prototype.delete=function(f){f=d(this,f);return f.o&&f.list?(f.list.splice(f.index,1),f.list.length||delete this.b[f.id],f.o.A.next=f.o.next,f.o.next.A=f.o.A,f.o.head=null,
this.size--,!0):!1};e.prototype.clear=function(){this.b={};this.a=this.a.A=b();this.size=0};e.prototype.has=function(f){return!!d(this,f).o};e.prototype.get=function(f){return(f=d(this,f).o)&&f.value};e.prototype.entries=function(){return c(this,function(f){return[f.key,f.value]})};e.prototype.keys=function(){return c(this,function(f){return f.key})};e.prototype.values=function(){return c(this,function(f){return f.value})};e.prototype.forEach=function(f,h){for(var k=this.entries(),m;!(m=k.next()).done;)m=
m.value,f.call(h,m[1],m[0],this)};e.prototype[Symbol.iterator]=e.prototype.entries;var l=0;return e});w('Object.values',function(a){return a?a:function(b){var c=[],d;for(d in b)u(b,d)&&c.push(b[d]);return c}});
w('Set',function(a){function b(c){this.a=new Map;if(c){c=p(c);for(var d;!(d=c.next()).done;)this.add(d.value)}this.size=this.a.size}if(function(){if(!a||'function'!=typeof a||!a.prototype.entries||'function'!=typeof Object.seal)return!1;try{var c=Object.seal({x:4}),d=new a(p([c]));if(!d.has(c)||1!=d.size||d.add(c)!=d||1!=d.size||d.add({x:4})!=d||2!=d.size)return!1;var e=d.entries(),g=e.next();if(g.done||g.value[0]!=c||g.value[1]!=c)return!1;g=e.next();return g.done||g.value[0]==c||4!=g.value[0].x||
g.value[1]!=g.value[0]?!1:e.next().done}catch(l){return!1}}())return a;x();b.prototype.add=function(c){c=0===c?0:c;this.a.set(c,c);this.size=this.a.size;return this};b.prototype.delete=function(c){c=this.a.delete(c);this.size=this.a.size;return c};b.prototype.clear=function(){this.a.clear();this.size=0};b.prototype.has=function(c){return this.a.has(c)};b.prototype.entries=function(){return this.a.entries()};b.prototype.values=function(){return this.a.values()};b.prototype.keys=b.prototype.values;
b.prototype[Symbol.iterator]=b.prototype.values;b.prototype.forEach=function(c,d){var e=this;this.a.forEach(function(g){return c.call(d,g,g,e)})};return b});w('Object.is',function(a){return a?a:function(b,c){return b===c?0!==b||1/b===1/c:b!==b&&c!==c}});w('Array.prototype.includes',function(a){return a?a:function(b,c){var d=this;d instanceof String&&(d=String(d));var e=d.length;c=c||0;for(0>c&&(c=Math.max(c+e,0));c<e;c++){var g=d[c];if(g===b||Object.is(g,b))return!0}return!1}});
w('Object.entries',function(a){return a?a:function(b){var c=[],d;for(d in b)u(b,d)&&c.push([d,b[d]]);return c}});
var y={pa:'loaded',wa:'start',ia:'firstQuartile',ra:'midpoint',xa:'thirdQuartile',ha:'complete',sa:'pause',ua:'resume',ga:'bufferStart',fa:'bufferFinish',va:'skipped',za:'volumeChange',ta:'playerStateChange',ca:'adUserInteraction'},na={ma:'generic',ya:'video',qa:'media'},pa={P:'native',na:'html',O:'javascript'},qa={P:'native',O:'javascript',NONE:'none'},ra={ka:'full',oa:'limited'},sa={ea:'backgrounded',ja:'foregrounded'},ta={da:'app',Aa:'web'};function A(a,b){this.x=null!=a.x?a.x:a.left;this.y=null!=a.y?a.y:a.top;this.width=a.width;this.height=a.height;this.endX=this.x+this.width;this.endY=this.y+this.height;this.adSessionId=a.adSessionId||void 0;this.isFriendlyObstructionFor=a.isFriendlyObstructionFor||[];this.b=a.friendlyObstructionClass||void 0;this.c=a.friendlyObstructionPurpose||void 0;this.f=a.friendlyObstructionReason||void 0;this.clipsToBounds=void 0!==a.clipsToBounds?!0===a.clipsToBounds:!0;this.notVisibleReason=a.notVisibleReason||
void 0;this.childViews=a.childViews||[];this.isCreative=a.isCreative||!1;this.a=b}function ua(a){var b={};return b.width=a.width,b.height=a.height,b}function C(a){var b={};return Object.assign({},ua(a),(b.x=a.x,b.y=a.y,b))}function va(a){var b=C(a),c={};return Object.assign({},b,(c.endX=a.endX,c.endY=a.endY,c))}function wa(a,b,c){a.x+=b;a.y+=c;a.endX+=b;a.endY+=c}
A.prototype.H=function(a){if(null==a)return!1;a=C(a);var b=a.y,c=a.width,d=a.height;return this.x===a.x&&this.y===b&&this.width===c&&this.height===d};function ya(a){return a.width*a.height};function za(a,b){a=C(a);for(var c=[],d=[],e=0;e<b.length;e++){var g=C(b[e]);g=Aa(a,g);Ba(c,g.x);Ba(c,g.endX);Ba(d,g.y);Ba(d,g.endY)}c=c.sort(function(l,f){return l-f});d=d.sort(function(l,f){return l-f});return{aa:c,ba:d}}function Aa(a,b){return{x:Math.max(a.x,b.x),y:Math.max(a.y,b.y),endX:Math.min(a.x+a.width,b.x+b.width),endY:Math.min(a.y+a.height,b.y+b.height)}}function Ba(a,b){-1===a.indexOf(b)&&a.push(b)};function Ca(){this.b=this.a=this.s=this.l=this.c=this.j=void 0;this.u=0;this.g=[];this.m=[];this.v=0;this.h=[];this.f=[];this.i=[]}Ca.prototype.H=function(a){return null==a?!1:JSON.stringify(Da(this))===JSON.stringify(Da(a))};
function Da(a){var b=[],c=[],d={viewport:a.j,adView:{percentageInView:a.u,reasons:a.i},declaredFriendlyObstructions:a.g.length};if(void 0!==a.a){d.adView.geometry=C(a.a);d.adView.geometry.pixels=ya(a.a);d.adView.onScreenGeometry=C(a.b);d.adView.onScreenGeometry.pixels=a.v;for(var e=0;e<a.f.length;e++)b.push(C(a.f[e]));for(e=0;e<a.m.length;e++){var g=a.m[e],l=g,f={};l.b&&(f.obstructionClass=l.b);l.c&&(f.obstructionPurpose=l.c);l.f&&(f.obstructionReason=l.f);g=Aa(a.a,g);c.push(Object.assign({},{x:g.x,
y:g.y,width:g.endX-g.x,height:g.endY-g.y},f))}d.adView.onScreenGeometry.obstructions=b;d.adView.onScreenGeometry.friendlyObstructions=c;void 0!==a.l&&void 0!==a.s&&(d.adView.containerGeometry=C(a.l),d.adView.onScreenContainerGeometry=C(a.s),d.adView.measuringElement=!0)}return d}function Ea(a,b){b=ua(b);a.j={};a.j.width=b.width;a.j.height=b.height;a.c={};a.c.x=0;a.c.y=0;a.c.width=b.width;a.c.height=b.height;a.c.endX=b.width;a.c.endY=b.height}
function Fa(){return{x:0,y:0,endX:0,endY:0,width:0,height:0}}function Ga(a,b){var c={};c.x=Math.max(a.x,b.x);c.y=Math.max(a.y,b.y);c.endX=Math.min(a.endX,b.endX);c.endY=Math.min(a.endY,b.endY);c.width=Math.max(0,c.endX-c.x);c.height=Math.max(0,c.endY-c.y);return c}function Ha(a,b){return a.width<b.width||a.height<b.height}
function Ia(a){var b=ya(a.a);if(0!==b){var c=ya(a.b);var d=a.f,e=0;if(0<d.length){var g=za(a.b,d),l=g.aa;g=g.ba;for(var f=0;f<l.length-1;f++)for(var h=(l[f]+(l[f]+1))/2,k=l[f+1]-l[f],m=0;m<g.length-1;m++){for(var z=(g[m]+(g[m]+1))/2,xa=g[m+1]-g[m],P=!1,Q=0;Q<d.length;Q++){var F=C(d[Q]);if(F.x<h&&F.x+F.width>h&&F.y<z&&F.y+F.height>z){P=!0;break}}P&&(e+=Math.round(k)*Math.round(xa))}}c-=e;b=Math.round(c/b*100);a.u=Math.max(b,0);a.v=Math.max(c,0)}}
function Ja(a,b){if(0!==b.width&&0!==b.height&&a.b){a=va(a.b);var c=a.y,d=a.endX,e=a.endY;b=!(b.endX<=a.x||b.x>=d||b.endY<=c||b.y>=e)}else b=!1;return b}function D(a,b){for(var c=!1,d=0;d<a.i.length;d++)a.i[d]===b&&(c=!0);c||a.i.push(b)};function Ka(a,b,c,d){var e=new Ca;b=new A(b,!1);Ea(e,b);La(a,b,e,d);if('backgrounded'===c)D(e,'backgrounded');else if(void 0!==e.a){for(a=0;a<e.g.length;a++)Ja(e,e.g[a])&&e.m.push(e.g[a]);for(a=0;a<e.h.length;a++){if(c=Ja(e,e.h[a])){a:{c=e.h[a];for(d=0;d<e.f.length;d++)if(e.f[d].H(c)){c=!0;break a}c=!1}c=!c}c&&(D(e,'obstructed'),e.f.push(e.h[a]))}Ia(e)}else D(e,'notFound');return e}
function La(a,b,c,d){var e=b.isCreative?!0:b.adSessionId===d;if(e){c.a=b;var g=va(c.a);a=Ga(c.c,g);var l=c.a;'notAttached'===l.notVisibleReason||'noWindowFocus'===l.notVisibleReason||'noAdView'===l.notVisibleReason?(D(c,'notFound'),c.b=new A(Fa(),!1)):(l=c.a,'viewInvisible'===l.notVisibleReason||'viewGone'===l.notVisibleReason||'viewNotVisible'===l.notVisibleReason||'viewAlphaZero'===l.notVisibleReason||'viewHidden'===l.notVisibleReason||void 0!==c.a.notVisibleReason?(D(c,'hidden'),c.b=new A(Fa(),
!1)):(Ha(a,g)&&D(c,'clipped'),c.b=new A(a,!1)))}else if(g=!0,b.a&&(g=-1!==b.isFriendlyObstructionFor.indexOf(d)?!1:!1===b.clipsToBounds),g){l=b.childViews;for(var f=0;f<l.length;f++)g=void 0!==c.a,La(a,new A(l[f],g),c,d)}e||void 0===c.a||(b.a?-1!==b.isFriendlyObstructionFor.indexOf(d)?c.g.push(b):c.h.push(b):(e=va(b),d=va(c.b),C(c.b),a=c.b,0!==a.width&&0!==a.height&&b.clipsToBounds&&(b=Ga(d,e),Ha(b,d)&&(D(c,'clipped'),c.b=new A(b,!1)))))};function Ma(a,b){this.y=this.x=0;this.width=a;this.height=b};function Na(){return{apiVersion:'1.0',accessMode:'limited',environment:'app',omidJsInfo:{omidImplementer:'omsdk',serviceVersion:'1.3.9-iab2283'}}}function Oa(){this.adSessionId=null;this.c=Na();this.s=null;this.m='foregrounded';this.l=this.g='none';this.j=this.i=this.h=this.f=this.a=this.b=this.B=this.u=null;this.C=!0;this.v=new Map}var E;function G(){E||(E=new Oa);return E};var Pa=eval('this'),H=function(){if('undefined'!==typeof omidGlobal&&omidGlobal)return omidGlobal;if('undefined'!==typeof global&&global)return global;if('undefined'!==typeof window&&window)return window;if('undefined'!==typeof Pa&&Pa)return Pa;throw Error('Could not determine global object context.');}();function Qa(a,b){this.a=a;this.b=b}t.Object.defineProperties(Qa.prototype,{event:{configurable:!0,enumerable:!0,get:function(){return this.a}},origin:{configurable:!0,enumerable:!0,get:function(){return this.b}}});function I(a){for(var b=[],c=0;c<arguments.length;++c)b[c]=arguments[c];Ra(function(){throw new (Function.prototype.bind.apply(Error,[null,'Could not complete the test successfully - '].concat(q(b))));},function(){return console.error.apply(console,q(b))})}function Sa(a){for(var b=[],c=0;c<arguments.length;++c)b[c]=arguments[c];Ra(function(){},function(){return console.error.apply(console,q(b))})}
function Ra(a,b){'undefined'!==typeof jasmine&&jasmine?a():'undefined'!==typeof console&&console&&console.error&&b()};function Ta(){this.f=[];this.b=[];this.c=[];this.g=[];this.i={};this.a=G()}function Ua(a){a.f=[];a.b=[];a.c=[];a.g=[];a.i={};E.adSessionId=null;E.c=Na();E.s=null;E.G=void 0;E.la=void 0;E.I=null;E.J=null;E.F=null;E.m='foregrounded';E.g='none';E.l='none';E.u=null;E.B=null;E.b=null;E.a=null;E.f=null;E.h=null;E.i=null;E.j=null;E.C=!0;E.v=new Map}
function Va(a,b){void 0!==a.a&&a.a.adSessionId&&!1!==Wa(a,b)&&a.c.filter(function(c){return c.type===b.event.type}).forEach(function(c){return a.h(c.D,b.event)})}function Xa(a,b){a.f.push(b);Va(a,b)}function Ya(a,b,c){void 0!==a.a&&a.a.adSessionId&&a.f.filter(function(d){return d.event.type===b&&Wa(a,d)}).map(function(d){return d.event}).forEach(c)}
function Wa(a,b){var c=b.event.type,d=-1!==Object.values(y).indexOf(c)&&'volumeChange'!==c;return'impression'===c||'loaded'===c&&a.a.a?b.origin===G().l:d?b.origin===G().g:!0}function Za(a,b,c){'media'===b||'video'===b?$a(a,c):(a.c.push({type:b,D:c}),Ya(a,b,c))}function $a(a,b){Object.keys(y).forEach(function(c){c=y[c];a.c.push({type:c,D:b});Ya(a,c,b)})}function ab(a,b,c,d){var e={N:c,K:d,D:b};a.g.push(e);a.b.forEach(function(g){var l=bb(g);'sessionStart'===g.event.type&&cb(a,l,e);a.h(b,l)})}
function db(a,b,c){var d=J(a,'sessionError','native',{errorType:b,message:c});a.b.push(d);a.g.forEach(function(e){a.h(e.D,d.event)})}function eb(a,b){a.i=Object.assign(a.i,b);b=a.a.c;if(void 0!==b){b=Object.assign({},fb(a,gb(a,{context:b}),!0),{supportsLoadedEvent:!!a.a.a||'video'==a.a.b});Object.assign(b,{pageUrl:null,contentUrl:a.a.s});var c=J(a,'sessionStart','native',b);a.b.push(c);a.g.forEach(function(d){var e=d.D,g=bb(c);cb(a,g,d);a.h(e,g)},a);hb(a)}}
function cb(a,b,c){c.N&&(b.data.verificationParameters=a.i[c.N]);c.K&&(a=a.a.v.get(c.K))&&(b.data.verificationParameters=a.verificationParameters,b.data.context.accessMode=a.accessMode)}function ib(a){var b=a.g,c=J(a,'sessionFinish','native');a.b.push(c);var d=a.a.c;d&&'native'==d.adSessionType||Ua(a);b.forEach(function(e){return a.h(e.D,c.event)})}Ta.prototype.h=function(a,b){for(var c=[],d=1;d<arguments.length;++d)c[d-1]=arguments[d];try{a.apply(null,q(c))}catch(e){Sa(e)}};
function jb(a,b){var c=(c=G().F)?Da(c):void 0;c=fb(a,gb(a,c));Xa(a,J(a,'impression',b,c))}function kb(a,b,c){if(a.a.a||'display'!=a.a.b)b=J(a,'loaded',b,fb(a,gb(a,void 0===c?null:c))),Xa(a,b)}
function lb(a,b,c,d){'start'!==b&&'volumeChange'!==b||null!=(d&&d.deviceVolume)||(d.deviceVolume=a.a.u);if(d&&('start'===b||'volumeChange'===b)){var e=d.videoPlayerVolume,g=d.mediaPlayerVolume;null!=e?(Object.assign(d,{mediaPlayerVolume:e}),a.a.B=e):null!=g&&(Object.assign(d,{videoPlayerVolume:g}),a.a.B=g)}Xa(a,J(a,b,c,d))}
function hb(a){var b=a.a.g,c=a.f.filter(function(l){return Object.values(y).includes(l.event.type)&&l.origin===b}).map(function(l){return l.event}),d=a.a.adSessionId||'',e={};c=p(c);for(var g=c.next();!g.done;e={w:e.w},g=c.next()){e.w=g.value;e.w.adSessionId||(e.w.adSessionId=d);if('loaded'==e.w.type){if(!a.a.a&&'display'==a.a.b)continue;e.w.data=fb(a,gb(a,e.w.data))}a.c.filter(function(l){return function(f){return f.type===l.w.type}}(e)).forEach(function(l){return function(f){return f.D(l.w)}}(e))}}
function mb(a,b,c){a:{c=new Set(c);a=p(a.f.concat(a.b));for(var d=a.next();!d.done;d=a.next())if(d=d.value,c.has(d.event.type)&&d.origin!=b){b=!0;break a}b=!1}return b?(I('Event owner cannot be registered after its events have already been published.'),!1):!0}function nb(a,b){mb(a,b,Object.values(y))&&K(a,b)&&(a.a.g=b)}function ob(a,b){mb(a,b,['impression'])&&pb(a,b)&&(a.a.l=b)}function pb(a,b){var c=a.a.l;return'none'!=c&&c!=b?(I('Impression event is owned by '+(a.a.l+', not ')+(b+'.')),!1):!0}
function K(a,b){var c=a.a.g;return'none'!=c&&c!=b?(I('Media events are owned by '+(a.a.g+', not '+b+'.')),!1):!0}function fb(a,b,c){c=void 0===c?!1:c;b=Object.assign({},b);a.a.b&&Object.assign(b,{mediaType:a.a.b});a.a.a&&(c||'definedByJavaScript'!==a.a.a)&&Object.assign(b,{creativeType:a.a.a});return b}function gb(a,b){return a.a.f?Object.assign({},b,{impressionType:a.a.f}):b}function J(a,b,c,d){return new Qa({adSessionId:a.a.adSessionId||'',timestamp:(new Date).getTime(),type:b,data:d},c)}
function bb(a){a=a.event;return{adSessionId:a.adSessionId,timestamp:a.timestamp,type:a.type,data:a.data}};function qb(a,b,c){'container'===b&&void 0!==a.a.G&&void 0!==a.a&&null!=a.a.adSessionId&&(a.a.I=Ka(a.c,a.a.G,a.a.m,a.a.adSessionId));b=a.a;var d=b.I,e=b.J;if(d)if(e){b=new Ca;var g=d.j,l=d.a,f=d.b,h=e.a;e=e.b;g&&l&&f&&h&&e&&(Ea(b,g),b.l=new A(l,!1),b.s=new A(f,!1),b.h=Object.assign([],d.h),b.f=Object.assign([],d.f),b.g=Object.assign([],d.g),b.m=Object.assign([],d.m),b.i=Object.assign([],d.i),d=b.l.x,g=b.l.y,h=new A(h,!1),e=new A(e,!1),wa(h,d,g),wa(e,d,g),b.a=h,b.b=Ga(e,f),-1===b.i.indexOf('backgrounded')&&
Ia(b))}else b=d;else b=null;f=a.a.F;if(b&&!b.H(f)||c)f=Da(b),c&&(f.adView.reasons=f.adView.reasons||[c]),c=a.b,'audio'!=c.a.a&&Xa(c,J(c,'geometryChange','native',f)),a.a.F=b};function L(a,b,c){this.f=a;this.I=b;this.F=c;this.c=G();this.b=null;this.a=this.g=this.u=void 0;this.G=!0;this.C=void 0;M(this)}function M(a){if(!a.b){var b;a:{if((b=a.f.document)&&b.getElementsByClassName&&(b=b.getElementsByClassName('omid-element'))){if(1==b.length){b=b[0];break a}1<b.length&&a.G&&(db(a.F,'generic',"More than one element with 'omid-element' class name."),a.G=!1)}b=null}b&&(b.tagName&&'video'===b.tagName.toLowerCase()?a.c.i=b:a.c.h=b,rb(a))}}
function rb(a){a.c.i?(a.b=a.c.i,a.i()):a.c.h&&(a.b=a.c.h,'iframe'===a.b.tagName.toLowerCase()?a.c.j&&a.i():a.i())}function sb(a){a.a&&(a.b.tagName&&'iframe'===a.b.tagName.toLowerCase()?a.c.j&&(a.B(),tb(a)):(a.B(),tb(a)))}L.prototype.m=function(){this.C&&(this.f.document.removeEventListener('visibilitychange',this.C),this.C=void 0)};L.prototype.i=function(){};function tb(a){a.u&&(a.c.J=a.u,qb(a.I,'creative'))}
function ub(a){if(a.a&&a.c.j){var b=new A(a.c.j,!1);wa(b,a.a.x,a.a.y);b.clipsToBounds=!0;return b}};function vb(a,b,c){return wb(a,'setInterval')(b,c)}function xb(a,b){wb(a,'clearInterval')(b)}function yb(a,b){wb(a,'clearTimeout')(b)}function wb(a,b){return a.a&&a.a[b]?a.a[b]:zb(a,b)}
function Ab(a,b,c,d){if(a.a.document&&a.a.document.body){var e=a.a.document.createElement('img');e.width=1;e.height=1;e.style.display='none';e.src=b;c&&e.addEventListener('load',function(){return c()});d&&e.addEventListener('error',function(){return d()});a.a.document.body.appendChild(e)}else zb(a,'sendUrl')(b,c,d)}function zb(a,b){if(a.a&&a.a.omidNative&&a.a.omidNative[b])return a.a.omidNative[b].bind(a.a.omidNative);throw Error('Native interface method "'+b+'" not found.');};function N(a,b,c,d,e){L.call(this,a,c,e);this.l=b;this.h=void 0;this.j=d}r(N,L);N.prototype.m=function(){void 0!==this.h&&(xb(this.j,this.h),this.h=void 0);L.prototype.m.call(this)};N.prototype.i=function(){var a=this;L.prototype.i.call(this);null==this.b?this.h=void 0:void 0===this.h&&(this.h=vb(this.j,function(){return Bb(a)},200),Bb(this))};
N.prototype.B=function(){if(this.g){var a=ub(this);if(a){this.a.isCreative=!1;a.isCreative=!0;for(var b=!1,c=0;c<this.a.childViews.length;c++)if(this.a.childViews[c].isCreative){this.a.childViews[c]=a;b=!0;break}b||this.a.childViews.push(a)}else this.a.isCreative=!0;this.u=Ka(this.l,this.g,this.c.m,this.c.adSessionId)}};
function Bb(a){if(void 0!==a.h){b:{try{var b=a.f.top;var c=0<=b.innerHeight&&0<=b.innerWidth;break b}catch(d){}c=!1}c?(c=a.f.top,c=new A(new Ma(c.innerWidth,c.innerHeight),!1)):c=new A(new Ma(0,0),!1);b=a.b.getBoundingClientRect();if(null==b.x||isNaN(b.x))b.x=b.left;if(null==b.y||isNaN(b.y))b.y=b.top;b=new A(b,!1);c.H(a.g)&&b.H(a.a)||(a.a=b,a.a.clipsToBounds=!0,a.g=c,a.g.childViews.push(a.a),sb(a))}};function O(a,b,c,d){L.call(this,a,c,d);this.v=this.s=this.j=this.l=this.h=void 0}r(O,L);O.prototype.m=function(){this.h&&this.h.disconnect();Cb(this);L.prototype.m.call(this)};O.prototype.i=function(){L.prototype.i.call(this);this.b&&(this.h||(this.h=Db(this)),Eb(this),Fb(this.b)&&Gb(this))};
O.prototype.B=function(){if(this.a&&this.v){var a=ub(this);if(a){var b=a;var c=this.v;var d=Math.max(a.x,c.x);var e=Math.max(a.y,c.y),g=Math.min(a.endX,c.endX);a=Math.min(a.endY,c.endY);g<=d||a<=e?d=null:(c={},d=new A((c.x=d,c.y=e,c.width=Math.abs(g-d),c.height=Math.abs(a-e),c),!1));d||(d=new A({x:0,y:0,width:0,height:0},!1))}else b=this.a,d=this.v;e=new Ca;this.g&&Ea(e,this.g);e.a=b;e.b=d;Ia(e);this.u=e}};
function Cb(a){a.l&&(a.l.disconnect(),a.l=void 0);a.j&&(a.j.disconnect(),a.j=void 0);a.s&&((0,a.f.removeEventListener)('resize',a.s),a.s=void 0)}function Eb(a){a.h&&a.b&&(a.h.unobserve(a.b),a.h.observe(a.b))}function Fb(a){a=a.getBoundingClientRect();return 0==a.width||0==a.height}
function Db(a){return new a.f.IntersectionObserver(function(b){try{if(b.length){for(var c,d=b[0],e=1;e<b.length;e++)b[e].time>d.time&&(d=b[e]);c=d;a.g=Hb(c.rootBounds);a.a=Hb(c.boundingClientRect);a.v=Hb(c.intersectionRect);sb(a)}}catch(g){a.m(),db(a.F,'generic','Problem handling IntersectionObserver callback: '+g.message)}},{root:null,rootMargin:'0px',threshold:[0,.1,.2,.3,.4,.5,.6,.7,.8,.9,1]})}
function Gb(a){a.f.ResizeObserver?a.l||(a.l=Ib(a,function(){return Kb(a)}),a.l.observe(a.b)):(a.s||(a.s=function(){return Kb(a)},(0,a.f.addEventListener)('resize',a.s)),a.j||(a.j=new MutationObserver(function(){return Kb(a)}),a.j.observe(a.b,{childList:!1,attributes:!0,subtree:!1})))}function Kb(a){a.b&&!Fb(a.b)&&(Eb(a),Cb(a))}function Ib(a,b){return new a.f.ResizeObserver(b)}function Hb(a){if(a&&null!==a.x&&null!==a.y&&null!==a.width&&null!==a.height)return new A(a,!1)};function R(a){return'object'===typeof a}function Lb(a){return'number'===typeof a&&!isNaN(a)&&0<=a}function S(a){return'string'===typeof a}function T(a,b){return S(a)&&-1!==Object.values(b).indexOf(a)};function Mb(a){return a&&R(a)?Object.entries(a).reduce(function(b,c){var d=p(c);c=d.next().value;d=d.next().value;return b&&S(c)&&null!=d&&R(d)&&S(d.resourceUrl)},!0):!1};function U(a,b,c,d){this.b=a;this.method=b;this.version=c;this.a=d}function Nb(a){return!!a&&void 0!==a.omid_message_guid&&void 0!==a.omid_message_method&&void 0!==a.omid_message_version&&'string'===typeof a.omid_message_guid&&'string'===typeof a.omid_message_method&&'string'===typeof a.omid_message_version&&(void 0===a.omid_message_args||void 0!==a.omid_message_args)}function Ob(a){return new U(a.omid_message_guid,a.omid_message_method,a.omid_message_version,a.omid_message_args)}
function Pb(a){var b={};b=(b.omid_message_guid=a.b,b.omid_message_method=a.method,b.omid_message_version=a.version,b);void 0!==a.a&&(b.omid_message_args=a.a);return b};function Qb(a){this.c=a};function V(a){this.c=a;this.handleExportedMessage=V.prototype.f.bind(this)}r(V,Qb);V.prototype.b=function(a,b){b=void 0===b?this.c:b;if(!b)throw Error('Message destination must be defined at construction time or when sending the message.');b.handleExportedMessage(Pb(a),this)};V.prototype.f=function(a,b){Nb(a)&&this.a&&this.a(Ob(a),b)};function Rb(a,b){this.c=b=void 0===b?H:b;var c=this;a.addEventListener('message',function(d){if('object'===typeof d.data){var e=d.data;Nb(e)&&d.source&&c.a&&c.a(Ob(e),d.source)}})}r(Rb,Qb);Rb.prototype.b=function(a,b){b=void 0===b?this.c:b;if(!b)throw Error('Message destination must be defined at construction time or when sending the message.');b.postMessage(Pb(a),'*')};function Sb(){return'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g,function(a){var b=16*Math.random()|0;return'y'===a?(b&3|8).toString(16):b.toString(16)})};function Tb(a){if(!a.b||!a.b.document)throw Error('OMID Service Script is not running within a window.');var b=a.a;a.a=[];b.forEach(function(c){var d=a.c.C?'limited':'full';var e=T(c.accessMode,ra)?c.accessMode:null;d=e?'full'==e&&'limited'==d?d:e:d;c.accessMode=d;e='full'!=d;d=Sb();var g=c.resourceUrl,l=a.b.document,f=l.createElement('iframe');e&&(f.sandbox='allow-scripts');f.id='omid-verification-script-frame-'+d;f.style.display='none';f.srcdoc="<html><head>\n<script type=\"text/javascript\">window['omidVerificationProperties'] = {\n'serviceWindow': window.parent,\n'injectionId': '"+
(d+'\',\n};\x3c/script>\n<script type="text/javascript" src="')+g.replace(/"/g,'&quot;')+'">\x3c/script>\n</head><body></body></html>';l.body.appendChild(f);e=c.vendorKey;g=c.verificationParameters;e=void 0===e?'':e;g=void 0===g?'':g;e&&'string'===typeof e&&''!==e&&g&&'string'===typeof g&&''!==g&&(a.f.i[e]=g);a.c.v.set(d,c)})};function Ub(){var a=Vb,b=Wb,c=this;this.c=X;this.b=a;this.a=G();this.g=b;this.f=!1;this.registerSessionObserver(function(d){return Xb(c,d)})}n=Ub.prototype;n.registerSessionObserver=function(a){ab(this.c,a)};n.setSlotElement=function(a){this.a.h=a;this.b&&rb(this.b)};n.setElementBounds=function(a){this.a.j=a;this.b&&rb(this.b);this.b&&sb(this.b)};n.error=function(a,b){db(this.c,a,b)};n.registerAdEvents=function(){ob(this.c,'javascript')};n.registerMediaEvents=function(){nb(this.c,'javascript')};
function Y(a,b,c){'impression'==b?pb(a.c,'javascript')&&(jb(a.c,'javascript'),a.b&&M(a.b)):('loaded'==b?(c=void 0===c?null:c,K(a.c,'javascript')&&kb(a.c,'javascript',c)):K(a.c,'javascript')&&lb(a.c,b,'javascript',c),['loaded','start'].includes(b)&&a.b&&M(a.b))}n.injectVerificationScriptResources=function(a){var b=this.g;b.a.push.apply(b.a,q(a));if(this.f)try{Tb(this.g)}catch(c){I(c.message)}};
n.setCreativeType=function(a,b){b=void 0===b?null:b;if(!this.a.b||this.a.a)this.a.a=a,'video'==a||'audio'==a?this.a.b='video':'htmlDisplay'==a||'nativeDisplay'==a?this.a.b='display':'definedByJavaScript'==a&&b&&(this.a.b='none'==b?'display':'video')};n.setImpressionType=function(a){if(!this.a.b||this.a.a)this.a.f=a};
function Xb(a,b){if('sessionStart'===b.type){a.f=!0;try{Tb(a.g)}catch(c){I(c.message)}}'sessionFinish'===b.type&&(a.f=!1,(b=G().c)&&'native'==b.adSessionType||a.registerSessionObserver(function(c){return Xb(a,c)}))}n.setClientInfo=function(a,b,c){var d=this.a.c||{};d.omidJsInfo=Object.assign({},d.omidJsInfo,{sessionClientVersion:a,partnerName:b,partnerVersion:c});this.a.c=d;return this.a.c.omidJsInfo.serviceVersion};function Yb(a){return/\d+\.\d+\.\d+(-.*)?/.test(a)}function Zb(a){a=a.split('-')[0].split('.');for(var b=['1','0','3'],c=0;3>c;c++){var d=parseInt(a[c],10),e=parseInt(b[c],10);if(d>e)break;else if(d<e)return!1}return!0};function $b(a,b){return Yb(a)&&Zb(a)?b?b:[]:b&&'string'===typeof b?JSON.parse(b):[]};function ac(){var a=bc;var b=void 0===b?omidGlobal:b;this.a=a;this.f=b;this.b=new V;this.f.omid=this.f.omid||{};this.f.omid.v1_SessionServiceCommunication=this.b;this.c=b&&b.addEventListener&&b.postMessage?new Rb(b):null;this.g=null;this.b.a=this.h.bind(this);this.c&&(this.c.a=this.i.bind(this))}ac.prototype.h=function(a,b){cc(this,a,b,this.b)};
ac.prototype.i=function(a,b){this.g||(this.g=b);this.g!=b?I('The source window of session client post messages cannot be changed from the source of the first message.'):cc(this,a,b,this.c)};
function cc(a,b,c,d){function e(h){for(var k=[],m=0;m<arguments.length;++m)k[m]=arguments[m];k=new U(g,'response',f,Yb(f)&&Zb(f)?k:JSON.stringify(k));d.b(k,c)}var g=b.b,l=b.method,f=b.version;b=$b(f,b.a);try{dc(a,l,e,b)}catch(h){d.b(new U(g,'error',f,'\n        name: '+h.name+'\n        message: '+h.message+'\n        filename: '+h.filename+'\n        lineNumber: '+h.lineNumber+'\n        columnNumber: '+h.columnNumber+'\n        stack: '+h.stack+'\n        toString(): '+h.toString()),c)}}
function dc(a,b,c,d){switch(b){case 'SessionService.registerAdEvents':a.a.registerAdEvents();break;case 'SessionService.registerMediaEvents':a.a.registerMediaEvents();break;case 'SessionService.registerSessionObserver':a.a.registerSessionObserver(c);break;case 'SessionService.setSlotElement':c=p(d).next().value;a.a.setSlotElement(c);break;case 'SessionService.setVideoElement':c=p(d).next().value;a=a.a;a.a.i=c;a.b&&rb(a.b);break;case 'SessionService.setElementBounds':c=p(d).next().value;a.a.setElementBounds(c);
break;case 'SessionService.startSession':I('Session start from JS is not supported in mobile app.');break;case 'SessionService.finishSession':I('Session finish from JS is not supported in mobile app.');break;case 'SessionService.impressionOccurred':Y(a.a,'impression');break;case 'SessionService.loaded':(c=p(d).next().value)?(b={skippable:c.isSkippable,autoPlay:c.isAutoPlay,position:c.position},c.isSkippable&&(b.skipOffset=c.skipOffset),Y(a.a,'loaded',b)):Y(a.a,'loaded');break;case 'SessionService.start':b=
p(d);c=b.next().value;b=b.next().value;Y(a.a,'start',{duration:c,mediaPlayerVolume:b});break;case 'SessionService.firstQuartile':Y(a.a,'firstQuartile');break;case 'SessionService.midpoint':Y(a.a,'midpoint');break;case 'SessionService.thirdQuartile':Y(a.a,'thirdQuartile');break;case 'SessionService.complete':Y(a.a,'complete');break;case 'SessionService.pause':Y(a.a,'pause');break;case 'SessionService.resume':Y(a.a,'resume');break;case 'SessionService.bufferStart':Y(a.a,'bufferStart');break;case 'SessionService.bufferFinish':Y(a.a,
'bufferFinish');break;case 'SessionService.skipped':Y(a.a,'skipped');break;case 'SessionService.volumeChange':c={mediaPlayerVolume:p(d).next().value};Y(a.a,'volumeChange',c);break;case 'SessionService.playerStateChange':c={state:p(d).next().value};Y(a.a,'playerStateChange',c);break;case 'SessionService.adUserInteraction':c={interactionType:p(d).next().value};Y(a.a,'adUserInteraction',c);break;case 'SessionService.setClientInfo':var e=p(d);b=e.next().value;d=e.next().value;e=e.next().value;a=a.a.setClientInfo(b,
d,e);c(a);break;case 'SessionService.injectVerificationScriptResources':c=p(d).next().value;a.a.injectVerificationScriptResources(c);break;case 'SessionService.setCreativeType':c=p(d).next().value;a.a.setCreativeType(c);break;case 'SessionService.setImpressionType':c=p(d).next().value;a.a.setImpressionType(c);break;case 'SessionService.setContentUrl':c=p(d).next().value;a.a.a.s=c;break;case 'SessionService.sessionError':b=p(d),c=b.next().value,b=b.next().value,a.a.error(c,b)}};function Z(){var a=X,b=ec,c=fc,d=Vb;this.f=bc;this.a=a;this.c=b;this.h=c;this.g=d;this.b=G()}n=Z.prototype;
n.S=function(a){if(!(!(a&&R(a)&&T(a.impressionOwner,qa))||'videoEventsOwner'in a&&null!=a.videoEventsOwner&&!T(a.videoEventsOwner,qa)||'mediaEventsOwner'in a&&null!=a.mediaEventsOwner&&!T(a.mediaEventsOwner,qa))){if(a.creativeType&&a.impressionType){var b=a.mediaEventsOwner;null==this.b.a&&this.f.setCreativeType(a.creativeType,b);null==this.b.f&&(this.b.f=a.impressionType);nb(this.a,b)}else b=a.videoEventsOwner,this.b.b=null==b||'none'===b?'display':'video',this.b.a=null,this.b.f=null,nb(this.a,b);
ob(this.a,a.impressionOwner);a&&null!=a.isolateVerificationScripts&&'boolean'===typeof a.isolateVerificationScripts&&(this.b.C=a.isolateVerificationScripts)}};
n.V=function(a,b,c,d){var e;if(R(b)){if(e=T(b.environment,ta)&&T(b.adSessionType,pa))e=b.omidNativeInfo,e=R(e)?S(e.partnerName)&&S(e.partnerVersion):!1;e&&(e=b.app,e=R(e)?S(e.libraryVersion)&&S(e.appId):!1)}else e=!1;e&&(Mb(d)&&(this.b.v=new Map(Object.entries(d))),d=this.f,c=void 0===c?null:c,null==a&&(a=Sb()),d.a.adSessionId=a,a=d.a,e=a.c||{},b.omidJsInfo=Object.assign({},e.omidJsInfo||{},b.omidJsInfo||{}),e=b=Object.assign({},e,b),a.C||(null!=a.i?(e.videoElement=a.i,e.accessMode='full'):null!=
a.h&&(e.slotElement=a.h,e.accessMode='full')),a.c=b,void 0!==b.contentUrl&&(a.s=b.contentUrl),eb(d.c,c),d.b&&M(d.b))};n.T=function(){var a=this.f;ib(a.c);a.b.m()};n.Z=function(a){R(a)&&Lb(a.x)&&Lb(a.y)&&Lb(a.width)&&Lb(a.height)&&(this.b.G=a,qb(this.c,'container'))};n.$=function(a){T(a,sa)&&(this.b.m=a,'backgrounded'===a?qb(this.c,'container','backgrounded'):qb(this.c,'container'))};n.W=function(a){'impression'===a&&(this.L(),this.g&&M(this.g))};n.L=function(){pb(this.a,'native')&&jb(this.a,'native')};
n.U=function(a){a=void 0===a?null:a;K(this.a,'native')&&kb(this.a,'native',a)};n.error=function(a,b){T(a,na)&&db(this.a,a,b)};n.X=function(a,b){this.M(a,b)};n.M=function(a,b){K(this.a,'native')&&T(a,y)&&(void 0===b||R(b))&&('loaded'==a?kb(this.a,'native',b):lb(this.a,a,'native',b))};n.Y=function(a){if('none'!==this.a.a.g&&'number'===typeof a&&!isNaN(a)){this.b.u=a;a=this.h;var b=a.a.B;null!=b&&lb(a.b,'volumeChange','native',{mediaPlayerVolume:b,deviceVolume:a.a.u})}};Z.prototype.startSession=Z.prototype.V;
Z.prototype.error=Z.prototype.error;Z.prototype.finishSession=Z.prototype.T;Z.prototype.publishAdEvent=Z.prototype.W;Z.prototype.publishImpressionEvent=Z.prototype.L;Z.prototype.publishVideoEvent=Z.prototype.X;Z.prototype.publishMediaEvent=Z.prototype.M;Z.prototype.publishLoadedEvent=Z.prototype.U;Z.prototype.setNativeViewHierarchy=Z.prototype.Z;Z.prototype.setState=Z.prototype.$;Z.prototype.setDeviceVolume=Z.prototype.Y;Z.prototype.init=Z.prototype.S;function gc(){var a=X,b=hc;var c=void 0===c?H:c;this.g=a;this.a=b;this.h={};this.f={};this.c=new V;c.omid=c.omid||{};c.omid.v1_VerificationServiceCommunication=this.c;this.b=null;c&&c.addEventListener&&c.postMessage&&(this.b=new Rb(c));this.c.a=this.i.bind(this);this.b&&(this.b.a=this.j.bind(this))}function ic(a,b,c,d){Ab(a.a,b,c,d)}function jc(a,b,c,d){zb(a.a,'downloadJavaScriptResource')(b,c,d)}gc.prototype.j=function(a,b){this.b&&kc(this,a,b,this.b)};gc.prototype.i=function(a,b){kc(this,a,b,this.c)};
function kc(a,b,c,d){function e(B){for(var W=[],oa=0;oa<arguments.length;++oa)W[oa]=arguments[oa];W=new U(g,'response',f,Yb(f)&&Zb(f)?W:JSON.stringify(W));d.b(W,c)}var g=b.b,l=b.method,f=b.version;b=$b(f,b.a);try{switch(l){case 'VerificationService.addEventListener':var h=p(b).next().value;Za(a.g,h,e);break;case 'VerificationService.addSessionListener':var k=p(b),m=k.next().value,z=k.next().value;ab(a.g,e,m,z);break;case 'VerificationService.sendUrl':var xa=p(b).next().value;ic(a,xa,function(){return e(!0)},
function(){return e(!1)});break;case 'VerificationService.setTimeout':var P=p(b),Q=P.next().value,F=P.next().value;a.h[Q]=wb(a.a,'setTimeout')(e,F);break;case 'VerificationService.clearTimeout':var pc=p(b).next().value;yb(a.a,a.h[pc]);break;case 'VerificationService.setInterval':var Jb=p(b),qc=Jb.next().value,rc=Jb.next().value;a.f[qc]=vb(a.a,e,rc);break;case 'VerificationService.clearInterval':var sc=p(b).next().value;xb(a.a,a.f[sc]);break;case 'VerificationService.injectJavaScriptResource':var tc=
p(b).next().value;jc(a,tc,function(B){return e(!0,B)},function(){return e(!1)});break;case 'VerificationService.getVersion':p(b).next();var uc=G().c.omidJsInfo;e(uc.serviceVersion)}}catch(B){d.b(new U(g,'error',f,'\n              name: '+B.name+'\n              message: '+B.message+'\n              filename: '+B.filename+'\n              lineNumber: '+B.lineNumber+'\n              columnNumber: '+B.columnNumber+'\n              stack: '+B.stack+'\n              toString(): '+B.toString()+'\n          '),
c)}};function lc(){var a=H.document.createElement('iframe');a.id='omid_v1_present';a.name='omid_v1_present';a.style.display='none';H.document.body.appendChild(a)}function mc(){var a=new MutationObserver(function(b){b.forEach(function(c){'BODY'===c.addedNodes[0].nodeName&&(lc(),a.disconnect())})});a.observe(H.document.documentElement,{childList:!0})};var X=new Ta,hc=new function(){var a;this.a=a=void 0===a?omidGlobal:a};new gc;var nc=new function(){},oc=new function(){},ec=new function(){this.b=X;this.c=oc;this.a=G()},vc;H?vc=H.IntersectionObserver&&(H.MutationObserver||H.ResizeObserver)?new O(H,nc,ec,X):new N(H,oc,ec,hc,X):vc=null;var Vb=vc,Wb=new function(){var a=X;var b=void 0===b?H:b;this.f=a;this.b=b;this.c=G();this.a=[]},bc=new Ub,fc=new function(){var a=X,b=G();this.b=a;this.a=b};H.omidBridge=new Z;new ac;
if(H.frames&&H.document&&!('omid_v1_present'in H.frames)){var wc;if(wc=null==H.document.body)wc='MutationObserver'in H;wc?mc():H.document.body?lc():H.document.write('<iframe style="display:none" id="omid_v1_present" name="omid_v1_present"></iframe>')};
}).call(this, this);
