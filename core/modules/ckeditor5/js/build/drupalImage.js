!function(e,t){"object"==typeof exports&&"object"==typeof module?module.exports=t():"function"==typeof define&&define.amd?define([],t):"object"==typeof exports?exports.CKEditor5=t():(e.CKEditor5=e.CKEditor5||{},e.CKEditor5.drupalImage=t())}(self,(function(){return function(){var e={"ckeditor5/src/core.js":function(e,t,i){e.exports=i("dll-reference CKEditor5.dll")("./src/core.js")},"ckeditor5/src/ui.js":function(e,t,i){e.exports=i("dll-reference CKEditor5.dll")("./src/ui.js")},"ckeditor5/src/upload.js":function(e,t,i){e.exports=i("dll-reference CKEditor5.dll")("./src/upload.js")},"ckeditor5/src/utils.js":function(e,t,i){e.exports=i("dll-reference CKEditor5.dll")("./src/utils.js")},"dll-reference CKEditor5.dll":function(e){"use strict";e.exports=CKEditor5.dll}},t={};function i(r){var n=t[r];if(void 0!==n)return n.exports;var s=t[r]={exports:{}};return e[r](s,s.exports,i),s.exports}i.d=function(e,t){for(var r in t)i.o(t,r)&&!i.o(e,r)&&Object.defineProperty(e,r,{enumerable:!0,get:t[r]})},i.o=function(e,t){return Object.prototype.hasOwnProperty.call(e,t)};var r={};return function(){"use strict";i.d(r,{default:function(){return T}});var e=i("ckeditor5/src/core.js");function t(e,t,i){if(t.attributes)for(const[r,n]of Object.entries(t.attributes))e.setAttribute(r,n,i);t.styles&&e.setStyle(t.styles,i),t.classes&&e.addClass(t.classes,i)}function n(e){return e.createEmptyElement("img")}function s(e){const t=parseFloat(e);return!Number.isNaN(t)&&e===String(t)}const o=[{modelValue:"alignCenter",dataValue:"center"},{modelValue:"alignRight",dataValue:"right"},{modelValue:"alignLeft",dataValue:"left"}];class a extends e.Plugin{static get requires(){return["ImageUtils"]}static get pluginName(){return"DrupalImageEditing"}init(){const{editor:e}=this,{conversion:i}=e,{schema:r}=e.model;r.isRegistered("imageInline")&&r.extend("imageInline",{allowAttributes:["dataEntityUuid","dataEntityType","isDecorative","width","height"]}),r.isRegistered("imageBlock")&&r.extend("imageBlock",{allowAttributes:["dataEntityUuid","dataEntityType","isDecorative","width","height"]}),i.for("upcast").add(function(e){function t(t,i,r){const{viewItem:n}=i,{writer:s,consumable:a,safeInsert:l,updateConversionResult:u,schema:c}=r,d=[];let m;if(!a.test(n,{name:!0,attributes:"src"}))return;const g=a.test(n,{name:!0,attributes:"data-caption"});if(m=c.checkChild(i.modelCursor,"imageInline")&&!g?s.createElement("imageInline",{src:n.getAttribute("src")}):s.createElement("imageBlock",{src:n.getAttribute("src")}),e.plugins.has("ImageStyleEditing")&&a.test(n,{name:!0,attributes:"data-align"})){const e=n.getAttribute("data-align"),t=o.find((t=>t.dataValue===e));t&&(s.setAttribute("imageStyle",t.modelValue,m),d.push("data-align"))}if(g){const t=s.createElement("caption"),i=e.data.processor.toView(n.getAttribute("data-caption")),o=s.createDocumentFragment();r.consumable.constructor.createFrom(i,r.consumable),r.convertChildren(i,o);for(const e of Array.from(o.getChildren()))s.append(e,t);s.append(t,m),d.push("data-caption")}a.test(n,{name:!0,attributes:"data-entity-uuid"})&&(s.setAttribute("dataEntityUuid",n.getAttribute("data-entity-uuid"),m),d.push("data-entity-uuid")),a.test(n,{name:!0,attributes:"data-entity-type"})&&(s.setAttribute("dataEntityType",n.getAttribute("data-entity-type"),m),d.push("data-entity-type")),l(m,i.modelCursor)&&(a.consume(n,{name:!0,attributes:d}),u(m,i))}return e=>{e.on("element:img",t,{priority:"high"})}}(e)).attributeToAttribute({view:{name:"img",key:"width"},model:{key:"width",value:e=>s(e.getAttribute("width"))?`${e.getAttribute("width")}px`:`${e.getAttribute("width")}`}}).attributeToAttribute({view:{name:"img",key:"height"},model:{key:"height",value:e=>s(e.getAttribute("height"))?`${e.getAttribute("height")}px`:`${e.getAttribute("height")}`}}),i.for("downcast").add(function(){function e(e,t,i){const{item:r}=t,{consumable:n,writer:s}=i;if(!n.consume(r,e.name))return;const o=i.mapper.toViewElement(r),a=Array.from(o.getChildren()).find((e=>"img"===e.name));s.setAttribute("data-entity-uuid",t.attributeNewValue,a||o)}return t=>{t.on("attribute:dataEntityUuid",e)}}()).add(function(){function e(e,t,i){const{item:r}=t,{consumable:n,writer:s}=i;if(!n.consume(r,e.name))return;const o=i.mapper.toViewElement(r),a=Array.from(o.getChildren()).find((e=>"img"===e.name));s.setAttribute("data-entity-type",t.attributeNewValue,a||o)}return t=>{t.on("attribute:dataEntityType",e)}}()),i.for("dataDowncast").add(function(e){return t=>{t.on("insert:caption",((t,i,r)=>{const{consumable:n,writer:s,mapper:o}=r;if(!e.plugins.get("ImageUtils").isImage(i.item.parent)||!n.consume(i.item,"insert"))return;const a=e.model.createRangeIn(i.item),l=s.createDocumentFragment();o.bindElements(i.item,l);for(const{item:t}of Array.from(a)){const i={item:t,range:e.model.createRangeOn(t)},n=`insert:${t.name||"$text"}`;e.data.downcastDispatcher.fire(n,i,r);for(const n of t.getAttributeKeys())Object.assign(i,{attributeKey:n,attributeOldValue:null,attributeNewValue:i.item.getAttribute(n)}),e.data.downcastDispatcher.fire(`attribute:${n}`,i,r)}for(const e of s.createRangeIn(l).getItems())o.unbindViewElement(e);o.unbindViewElement(l);const u=e.data.processor.toData(l);if(u){const e=o.toViewElement(i.item.parent);s.setAttribute("data-caption",u,e)}}),{priority:"high"})}}(e)).elementToElement({model:"imageBlock",view:(e,{writer:t})=>n(t),converterPriority:"high"}).elementToElement({model:"imageInline",view:(e,{writer:t})=>n(t),converterPriority:"high"}).add(function(){function e(e,t,i){const{item:r}=t,{consumable:n,writer:s}=i,a=o.find((e=>e.modelValue===t.attributeNewValue));if(!a||!n.consume(r,e.name))return;const l=i.mapper.toViewElement(r),u=Array.from(l.getChildren()).find((e=>"img"===e.name));s.setAttribute("data-align",a.dataValue,u||l)}return t=>{t.on("attribute:imageStyle",e,{priority:"high"})}}()).add(function(){function e(e,t,i){const{item:r}=t,{consumable:n,writer:s}=i;if(!n.consume(r,e.name))return;const o=i.mapper.toViewElement(r),a=Array.from(o.getChildren()).find((e=>"img"===e.name));s.setAttribute("width",t.attributeNewValue.replace("px",""),a||o)}return t=>{t.on("attribute:width:imageInline",e,{priority:"high"}),t.on("attribute:width:imageBlock",e,{priority:"high"})}}()).add(function(){function e(e,t,i){const{item:r}=t,{consumable:n,writer:s}=i;if(!n.consume(r,e.name))return;const o=i.mapper.toViewElement(r),a=Array.from(o.getChildren()).find((e=>"img"===e.name));s.setAttribute("height",t.attributeNewValue.replace("px",""),a||o)}return t=>{t.on("attribute:height:imageInline",e,{priority:"high"}),t.on("attribute:height:imageBlock",e,{priority:"high"})}}()).add(function(){function e(e,i,r){if(!r.consumable.consume(i.item,e.name))return;const n=r.mapper.toViewElement(i.item),s=r.writer,o=s.createContainerElement("a",{href:i.attributeNewValue});s.insert(s.createPositionBefore(n),o),s.move(s.createRangeOn(n),s.createPositionAt(o,0)),r.consumable.consume(i.item,"attribute:htmlLinkAttributes:imageBlock")&&t(r.writer,i.item.getAttribute("htmlLinkAttributes"),o)}return t=>{t.on("attribute:linkHref:imageBlock",e,{priority:"high"})}}())}}class l extends e.Command{refresh(){const e=this.editor.plugins.get("ImageUtils").getClosestSelectedImageElement(this.editor.model.document.selection);this.isEnabled=!!e,this.isEnabled&&e.hasAttribute("alt")?this.value=e.getAttribute("alt"):this.value=!1}execute(e){const t=this.editor,i=t.plugins.get("ImageUtils"),r=t.model,n=i.getClosestSelectedImageElement(r.document.selection);r.change((t=>{t.setAttribute("alt",e.newValue,n)}))}}class u extends e.Plugin{static get requires(){return["ImageUtils"]}static get pluginName(){return"DrupalImageAlternativeTextEditing"}constructor(e){super(e),this._missingAltTextViewReferences=new Set}init(){const e=this.editor;e.conversion.for("editingDowncast").add(this._imageEditingDowncastConverter("attribute:alt",e)).add(this._imageEditingDowncastConverter("attribute:src",e)),e.commands.add("imageTextAlternative",new l(this.editor)),e.editing.view.on("render",(()=>{for(const e of this._missingAltTextViewReferences)e.button.element.isConnected||(e.destroy(),this._missingAltTextViewReferences.delete(e))}))}_imageEditingDowncastConverter(e){const t=(e,t,i)=>{const r=this.editor;if(!r.plugins.get("ImageUtils").isImage(t.item))return;const n=i.mapper.toViewElement(t.item),s=Array.from(n.getChildren()).find((e=>e.getCustomProperty("drupalImageMissingAltWarning")));if(t.item.hasAttribute("alt"))return void(s&&i.writer.remove(s));if(s)return;const o=r.ui.componentFactory.create("drupalImageAlternativeTextMissing");o.listenTo(r.ui,"update",(()=>{const e=r.model.document.selection.getFirstRange(),i=r.model.createRangeOn(t.item);o.set({isSelected:e.containsRange(i)||e.isIntersecting(i)})})),o.render(),this._missingAltTextViewReferences.add(o);const a=i.writer.createUIElement("span",{class:"image-alternative-text-missing-wrapper"},(function(e){const t=this.toDomElement(e);return t.appendChild(o.element),t}));i.writer.setCustomProperty("drupalImageMissingAltWarning",!0,a),i.writer.insert(i.writer.createPositionAt(n,"end"),a)};return i=>{i.on(e,t,{priority:"low"})}}}var c=i("ckeditor5/src/ui.js");function d(e){const t=e.plugins.get("ContextualBalloon");if(e.plugins.get("ImageUtils").getClosestSelectedImageWidget(e.editing.view.document.selection)){const i=m(e);t.updatePosition(i)}}function m(e){const t=e.editing.view,i=c.BalloonPanelView.defaultPositions,r=e.plugins.get("ImageUtils");return{target:t.domConverter.mapViewToDom(r.getClosestSelectedImageWidget(t.document.selection)),positions:[i.northArrowSouth,i.northArrowSouthWest,i.northArrowSouthEast,i.southArrowNorth,i.southArrowNorthWest,i.southArrowNorthEast,i.viewportStickyNorth]}}var g=i("ckeditor5/src/utils.js");class h extends c.View{constructor(t){super(t),this.focusTracker=new g.FocusTracker,this.keystrokes=new g.KeystrokeHandler,this.decorativeToggle=this._decorativeToggleView(),this.labeledInput=this._createLabeledInputView(),this.saveButtonView=this._createButton(Drupal.t("Save"),e.icons.check,"ck-button-save"),this.saveButtonView.type="submit",this.saveButtonView.bind("isEnabled").to(this.decorativeToggle,"isOn",this.labeledInput,"isEmpty",((e,t)=>e||!t)),this.cancelButtonView=this._createButton(Drupal.t("Cancel"),e.icons.cancel,"ck-button-cancel","cancel"),this._focusables=new c.ViewCollection,this._focusCycler=new c.FocusCycler({focusables:this._focusables,focusTracker:this.focusTracker,keystrokeHandler:this.keystrokes,actions:{focusPrevious:"shift + tab",focusNext:"tab"}}),this.setTemplate({tag:"form",attributes:{class:["ck","ck-text-alternative-form","ck-text-alternative-form--with-decorative-toggle","ck-responsive-form"],tabindex:"-1"},children:[{tag:"div",attributes:{class:["ck","ck-text-alternative-form__decorative-toggle"]},children:[this.decorativeToggle]},this.labeledInput,this.saveButtonView,this.cancelButtonView]}),(0,c.injectCssTransitionDisabler)(this)}render(){super.render(),this.keystrokes.listenTo(this.element),(0,c.submitHandler)({view:this}),[this.decorativeToggle,this.labeledInput,this.saveButtonView,this.cancelButtonView].forEach((e=>{this._focusables.add(e),this.focusTracker.add(e.element)}))}destroy(){super.destroy(),this.focusTracker.destroy(),this.keystrokes.destroy()}_createButton(e,t,i,r){const n=new c.ButtonView(this.locale);return n.set({label:e,icon:t,tooltip:!0}),n.extendTemplate({attributes:{class:i}}),r&&n.delegate("execute").to(this,r),n}_createLabeledInputView(){const e=new c.LabeledFieldView(this.locale,c.createLabeledInputText);return e.bind("class").to(this.decorativeToggle,"isOn",(e=>e?"ck-hidden":"")),e.label=Drupal.t("Text alternative"),e}_decorativeToggleView(){const e=new c.SwitchButtonView(this.locale);return e.set({withText:!0,label:Drupal.t("Decorative image")}),e.on("execute",(()=>{e.set("isOn",!e.isOn)})),e}}class p extends c.View{constructor(e){super(e);const t=this.bindTemplate;this.set("isVisible"),this.set("isSelected");const i=Drupal.t("Add missing alternative text");this.button=new c.ButtonView(e),this.button.set({label:i,tooltip:!1,withText:!0}),this.setTemplate({tag:"span",attributes:{class:["image-alternative-text-missing",t.to("isVisible",(e=>e?"":"ck-hidden"))],title:i},children:[this.button]})}}class f extends e.Plugin{static get requires(){return[c.ContextualBalloon]}static get pluginName(){return"DrupalImageTextAlternativeUI"}init(){this._createButton(),this._createForm(),this._createMissingAltTextComponent();const e=()=>{this.editor.plugins.get("ImageUtils").getClosestSelectedImageWidget(this.editor.editing.view.document.selection)&&this._showForm()};if(this.editor.commands.get("insertImage")){this.editor.commands.get("insertImage").on("execute",e)}if(this.editor.plugins.has("ImageUploadEditing")){this.editor.plugins.get("ImageUploadEditing").on("uploadComplete",e)}}_createMissingAltTextComponent(){this.editor.ui.componentFactory.add("drupalImageAlternativeTextMissing",(e=>{const t=new p(e);return t.listenTo(t.button,"execute",(()=>{this._isInBalloon&&this._balloon.remove(this._form),this._showForm()})),t.listenTo(this.editor.ui,"update",(()=>{t.set({isVisible:!this._isVisible||!t.isSelected})})),t}))}destroy(){super.destroy(),this._form.destroy()}_createButton(){const t=this.editor;t.ui.componentFactory.add("drupalImageAlternativeText",(i=>{const r=t.commands.get("imageTextAlternative"),n=new c.ButtonView(i);return n.set({label:Drupal.t("Change image alternative text"),icon:e.icons.lowVision,tooltip:!0}),n.bind("isEnabled").to(r,"isEnabled"),this.listenTo(n,"execute",(()=>{this._showForm()})),n}))}_createForm(){const e=this.editor,t=e.editing.view.document,i=e.plugins.get("ImageUtils");this._balloon=this.editor.plugins.get("ContextualBalloon"),this._form=new h(e.locale),this._form.render(),this.listenTo(this._form,"submit",(()=>{e.execute("imageTextAlternative",{newValue:this._form.decorativeToggle.isOn?"":this._form.labeledInput.fieldView.element.value}),this._hideForm(!0)})),this.listenTo(this._form,"cancel",(()=>{this._hideForm(!0)})),this.listenTo(this._form.decorativeToggle,"execute",(()=>{d(e)})),this._form.keystrokes.set("Esc",((e,t)=>{this._hideForm(!0),t()})),this.listenTo(e.ui,"update",(()=>{i.getClosestSelectedImageWidget(t.selection)?this._isVisible&&d(e):this._hideForm(!0)})),(0,c.clickOutsideHandler)({emitter:this._form,activator:()=>this._isVisible,contextElements:[this._balloon.view.element],callback:()=>this._hideForm()})}_showForm(){if(this._isVisible)return;const e=this.editor,t=e.commands.get("imageTextAlternative"),i=this._form.decorativeToggle,r=this._form.labeledInput;this._form.disableCssTransitions(),this._isInBalloon||this._balloon.add({view:this._form,position:m(e)}),i.isOn=""===t.value,r.fieldView.element.value=t.value||"",r.fieldView.value=r.fieldView.element.value,i.isOn?i.focus():r.fieldView.select(),this._form.enableCssTransitions()}_hideForm(e){this._isInBalloon&&(this._form.focusTracker.isFocused&&this._form.saveButtonView.focus(),this._balloon.remove(this._form),e&&this.editor.editing.view.focus())}get _isVisible(){return this._balloon.visibleView===this._form}get _isInBalloon(){return this._balloon.hasView(this._form)}}class b extends e.Plugin{static get requires(){return[u,f]}static get pluginName(){return"DrupalImageAlternativeText"}}class w extends e.Plugin{static get requires(){return[a,b]}static get pluginName(){return"DrupalImage"}}var v=w;class y extends e.Plugin{init(){const{editor:e}=this;e.plugins.get("ImageUploadEditing").on("uploadComplete",((t,{data:i,imageElement:r})=>{e.model.change((e=>{e.setAttribute("dataEntityUuid",i.response.uuid,r),e.setAttribute("dataEntityType",i.response.entity_type,r)}))}))}static get pluginName(){return"DrupalImageUploadEditing"}}var I=i("ckeditor5/src/upload.js");class x{constructor(e,t){this.loader=e,this.options=t}upload(){return this.loader.file.then((e=>new Promise(((t,i)=>{this._initRequest(),this._initListeners(t,i,e),this._sendRequest(e)}))))}abort(){this.xhr&&this.xhr.abort()}_initRequest(){this.xhr=new XMLHttpRequest,this.xhr.open("POST",this.options.uploadUrl,!0),this.xhr.responseType="json"}_initListeners(e,t,i){const r=this.xhr,n=this.loader,s=`Couldn't upload file: ${i.name}.`;r.addEventListener("error",(()=>t(s))),r.addEventListener("abort",(()=>t())),r.addEventListener("load",(()=>{const i=r.response;if(!i||i.error)return t(i&&i.error&&i.error.message?i.error.message:s);e({response:i,urls:{default:i.url}})})),r.upload&&r.upload.addEventListener("progress",(e=>{e.lengthComputable&&(n.uploadTotal=e.total,n.uploaded=e.loaded)}))}_sendRequest(e){const t=this.options.headers||{},i=this.options.withCredentials||!1;Object.keys(t).forEach((e=>{this.xhr.setRequestHeader(e,t[e])})),this.xhr.withCredentials=i;const r=new FormData;r.append("upload",e),this.xhr.send(r)}}class _ extends e.Plugin{static get requires(){return[I.FileRepository]}static get pluginName(){return"DrupalFileRepository"}init(){const e=this.editor.config.get("drupalImageUpload");e&&(e.uploadUrl?this.editor.plugins.get(I.FileRepository).createUploadAdapter=t=>new x(t,e):(0,g.logWarning)("simple-upload-adapter-missing-uploadurl"))}}class V extends e.Plugin{static get requires(){return[_,y]}static get pluginName(){return"DrupalImageUpload"}}var A=V;class E extends e.Plugin{init(){const{editor:e}=this;e.ui.componentFactory.add("drupalInsertImage",(()=>{if(e.plugins.has("ImageInsertUI"))return e.ui.componentFactory.create("insertImage");if(e.plugins.has("ImageUpload"))return e.ui.componentFactory.create("uploadImage");throw new Error("drupalInsertImage requires either ImageUpload or ImageInsertUI plugin to be enabled.")}))}static get pluginName(){return"DrupalInsertImage"}}var T={DrupalImage:v,DrupalImageUpload:A,DrupalInsertImage:E}}(),r=r.default}()}));