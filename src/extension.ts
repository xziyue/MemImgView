import * as vscode from 'vscode';
import { MemImgPanel } from './memImgPanel';

export function activate(context: vscode.ExtensionContext) {
	context.subscriptions.push(
		vscode.commands.registerCommand('memimgview.openPanel', () => {
			MemImgPanel.createOrShow(context);
		})
	);
}
